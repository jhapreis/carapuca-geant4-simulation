#include "logger/logmanager.hh"


LogManager::LogManager(std::string const& name, std::string const& loglevel, std::string const& pattern, std::string const& logfile):
    log_name(name),
    level(loglevel),
    log_pattern(pattern),
    log_file(logfile)
{
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    auto basic_sink   = std::make_shared<spdlog::sinks::basic_file_sink_mt>(log_file);

    std::vector<spdlog::sink_ptr> sinks{console_sink, basic_sink};
    auto logger = std::make_shared<spdlog::logger>(log_name, sinks.begin(), sinks.end());

    if(pattern != ""){
        logger->set_pattern(log_pattern);
    }

    logger->set_level( GetLogLevel(level) );

    spdlog::register_logger(logger);
}


LogManager::~LogManager() = default;


std::shared_ptr<spdlog::logger> LogManager::GetLogger() const{
    return spdlog::get(log_name);
}

 
spdlog::level::level_enum LogManager::GetLogLevel(std::string const &loglevel) const{

    auto spdlog_loglevel = level_mapping.find(loglevel);

    if(spdlog_loglevel == level_mapping.end()){
        return spdlog::level::level_enum::critical;
    }

    return spdlog_loglevel->second;
}
