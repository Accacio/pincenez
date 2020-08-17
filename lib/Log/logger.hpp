#pragma once
#include <iomanip>
#include <sstream>
#include <string>
#include <mutex>
#include <memory>
#include <fstream>

#include "types.hpp"
#include "policies.hpp"

class logger
{
	unsigned log_line_number;
	std::string get_time();
	std::string get_logline_header();
	std::string _name;
	std::stringstream log_stream;
	ILog_policy* _policy;
	std::mutex write_mutex;

	severity_type _severity=severity_type::none;

	// Core printing functionality
	template<severity_type severity>
	void print_impl();
	template<severity_type severity, typename First, typename...Rest>
	void print_impl(First parm1, Rest...parm);

	public:
		logger( const std::string& name, ILog_policy * policy);

		void setloggerlevel( severity_type severity );

		template< severity_type severity , typename...Args >
		void print( Args...args );

		~logger();
};

inline void logger::setloggerlevel( severity_type severity ){
	_severity=severity;
}

inline logger::logger( const std::string& name, ILog_policy * policy)
{
	// std::cout<< name << " being created" << std::endl;
	log_line_number = 0;
	_name = name;
	_policy = policy;
	// TODO
	if( !policy )
	{
		throw std::runtime_error("LOGGER: Unable to create the logger instance");
	}
}

inline logger::~logger()
{
	if( _policy )
	{
	delete _policy;
	}
}

template< severity_type severity , typename...Args >
inline void logger::print( Args...args )
{

	write_mutex.lock();
	if (_severity>=severity) {

	print_impl<severity>( args... );
	}
	write_mutex.unlock();
}


template< severity_type severity >
inline void logger::print_impl()
{
	_policy->write( get_logline_header() + log_stream.str(), severity );
	log_stream.str("");
}

template<severity_type severity, typename First, typename...Rest >
inline void logger::print_impl(First parm1, Rest...parm)
{
	log_stream<<parm1;
	print_impl<severity>(parm...);
}

inline std::string logger::get_time()
{
	char buffer [80];
	time_t raw_time;

	time( & raw_time );
	struct tm * timeinfo;
	timeinfo = localtime(&raw_time);
	strftime(buffer,80,"[%F %T%z]",timeinfo);
	std::string time_str = std::string(buffer);
	return time_str;
}

inline std::string logger::get_logline_header()
{
	std::stringstream header;

	header.str("");
	header.fill('0');
	header.width(7);
	header <<
		clock()
		   <<
		" "
		   <<
		get_time()
		;
	header.fill(' ');
	header<< " [" << std::setw(5) <<_name.substr(0,5) << "] ";

	return header.str();
}

