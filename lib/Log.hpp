#ifndef __LOG_HPP_
#define __LOG_HPP_

#include "Log/logger.hpp"

class Log {
    public:
        static void Init();
        virtual ~Log();
        static logger core_logger;
        static logger client_logger;

};


#define PCNLOG Log::core_logger.print< severity_type::info >
#define PCNLOG_DEBUG Log::core_logger.print< severity_type::debug >
#define PCNLOG_ERR Log::core_logger.print< severity_type::error >
#define PCNLOG_WARN Log::core_logger.print< severity_type::warning >

#define LOG Log::client_logger.print< severity_type::info >
#define LOG_DEBUG Log::client_logger.print< severity_type::debug >
#define LOG_ERR Log::client_logger.print< severity_type::error >
#define LOG_WARN Log::client_logger.print< severity_type::warning >

#endif // __LOG_HPP_
