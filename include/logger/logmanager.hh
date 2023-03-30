#pragma once

#include <memory>
#include <map>
#include <iostream>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"

#include "logger.hh"



class LogManager{

    public:
        LogManager(std::string const& name, std::string const& log_level, std::string const& pattern, std::string const& logfile);
        ~LogManager();

        std::shared_ptr<spdlog::logger> GetLogger() const;
    
    private:

        std::string log_name;
        std::string level;
        std::string log_pattern;
        std::string log_file;

        std::map<std::string, spdlog::level::level_enum> level_mapping = {
            {"debug"   , spdlog::level::level_enum::debug},
            {"info"    , spdlog::level::level_enum::info},
            {"warning" , spdlog::level::level_enum::warn},
            {"critical", spdlog::level::level_enum::critical}
        };

        spdlog::level::level_enum GetLogLevel(std::string const &loglevel) const;
};
