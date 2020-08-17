#ifndef __LOGPOLICY_H_
#define __LOGPOLICY_H_

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <memory>

#include "types.hpp"

class ILog_policy
{
	protected:
		ILog_policy(){};

	public:
		virtual void		write(const std::string& msg,severity_type severity) = 0;
		virtual ~ILog_policy(){};

};

inline void ILog_policy::write(const std::string& msg,severity_type severity){

}


class file_log_policy : public ILog_policy
{
	protected:
	std::unique_ptr< std::ofstream > out_stream;
	public:
		// file_log_policy(): out_stream(new std::ofstream) {};
		file_log_policy(const std::string& filename = "");
		void open_ostream(const std::string& name);
		void close_ostream();
		void write(const std::string& msg,severity_type severity);
		~file_log_policy();
};

inline file_log_policy::file_log_policy(const std::string& filename)
{
	out_stream = std::make_unique<std::ofstream>();
	open_ostream( filename );
	// if( out_stream )
	// {
	// 	close_ostream();
	// }
}

inline file_log_policy::~file_log_policy()
{
	if( out_stream )
	{
		close_ostream();
	}
}

inline void file_log_policy::open_ostream(const std::string& name)
{
	out_stream->open( name.c_str(), std::ios_base::binary|std::ios_base::out );
	if( !out_stream->is_open() )
	{
		throw(std::runtime_error("LOGGER: Unable to open an output stream"));
	}
}

inline void file_log_policy::close_ostream()
{
	if( out_stream )
	{
		out_stream->close();
	}
}

inline void file_log_policy::write(const std::string& msg,severity_type severity)
{

	switch( severity )
	{
		case severity_type::info:
			(*out_stream) << std::setw(7) << "INFO";
			break;
		case severity_type::debug:
			(*out_stream) << std::setw(7) << "DEBUG";
			break;
		case severity_type::warning:
			(*out_stream) << std::setw(7) <<"WARNING";
			break;
		case severity_type::error:
			// log_stream<<"<ERROR>   : ";
			(*out_stream) <<std::setw(7) <<"ERROR";
			break;
		default:
			break;
	};
	(*out_stream)<< " " << msg<<std::endl;
}

class file_log_policy_colored: public file_log_policy {

	public:
		file_log_policy_colored(const std::string& filename = "") : file_log_policy(filename) {};

		void write(const std::string& msg,severity_type severity);
};

inline void file_log_policy_colored::write(const std::string& msg,severity_type severity)
{

	switch( severity )
	{
		case severity_type::info:
			(*out_stream) ;
			break;
		case severity_type::debug:
			(*out_stream) << "\x1B[34m" ;
			break;
		case severity_type::warning:
			(*out_stream) << "\x1B[33m" ;
			break;
		case severity_type::error:
			// log_stream<<"<ERROR>   : ";
			(*out_stream) << "\x1B[31m" ;
			break;
		default:
			break;
	};
	(*out_stream) << msg<<"\033[0m"<<std::endl;
}


class console_log_policy : public ILog_policy
{
	public:
		console_log_policy()=default;
		void write(const std::string& msg,severity_type severity);
		~console_log_policy()=default;
};

inline void console_log_policy::write(const std::string& msg,severity_type severity)
{

	switch( severity )
	{
		case severity_type::info:
			std::cout << std::setw(7) << "INFO";
			break;
		case severity_type::debug:
			std::cout  << std::setw(7) << "DEBUG";
			break;
		case severity_type::warning:
			std::cout  << std::setw(7) <<"WARNING";
			break;
		case severity_type::error:
			// log_stream<<"<ERROR>   : ";
			std::cout  <<std::setw(7) <<"ERROR";
			break;
		default:
			break;
	};
	std::cout<< " " << msg<<std::endl;
}

class console_log_policy_colored: public console_log_policy {

	public:
		// console_log_policy_colored() : file_log_policy {};

		void write(const std::string& msg,severity_type severity);
};
inline void console_log_policy_colored::write(const std::string& msg,severity_type severity)
{

	switch( severity )
	{
		case severity_type::debug:
			std::cout << "\x1B[34m" ;
			break;
		case severity_type::warning:
			std::cout << "\x1B[33m" ;
			break;
		case severity_type::error:
			// log_stream<<"<ERROR>   : ";
			std::cout << "\x1B[31m" ;
			break;
		default:
			break;
	};
	std::cout << msg<<"\033[0m"<<std::endl;
}

#endif // __LOGPOLICY_H_
