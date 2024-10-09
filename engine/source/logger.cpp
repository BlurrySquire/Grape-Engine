#include "logger.hpp"

#include <iostream>
#include <fstream>

namespace GRAPE {
	Logger& Logger::GetLogger() {
		static Logger self;
		return self;
	}

	void Logger::SetLogFile(const std::string& filepath) {
		this->log_file = filepath;
	}

	void Logger::ClearLogFile() {
		std::fstream file(this->log_file, std::ios::out | std::ios::trunc);
		if (file.is_open()) {
			file.close();
		}
	}

	void Logger::LogMessage(const std::string& message, LogLevel level) {
		const std::string log_colours[7] = {
			"\033[0m",		// NONE
			"\033[97;41m",	// FATAL
			"\033[91m",		// ERROR
			"\033[93m",		// WARN
			"\033[94m",		// INFO
			"\033[92m",		// DEBUG
			"\033[37m"		// TRACE
		};

		std::cout << log_colours[level] << message << "\033[0m" << std::endl;

		// We don't write logs with a level of NONE to a file.
		if (level != LogLevel::NONE) {
			std::fstream file(this->log_file, std::ios::out | std::ios::app);
			if (file.is_open()) {
				file.write(message.c_str(), message.size());
				file.write("\n", 1);
				file.close();
			}
			else {
				this->LogMessage("Unable to write to log file.", LogLevel::NONE);
			}
		}
	}
};