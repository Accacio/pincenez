#include "Log.hpp"


logger Log::core_logger("PINCENEZ", new console_log_policy_colored);
logger Log::client_logger("APP", new console_log_policy_colored);

void Log::Init(){
    client_logger.setloggerlevel(severity_type::all);
    core_logger.setloggerlevel(severity_type::all);
}
