#include "logger.hpp"

#include <iostream>
#include <fstream>

namespace GRAPE {
	Logger::Logger(const std::string& log_name) {
		this->log_file = log_name;
		
		// Reset log file
		std::fstream file(this->log_file, std::ios::out | std::ios::trunc);
		if (file.is_open()) {
			file.close();
		}
	}

	void Logger::LogMessage(const std::string& message, const std::string& colour) {
		std::cout << colour << message << "\033[0m" << std::endl;

		std::fstream file(this->log_file, std::ios::out | std::ios::app);
		if (file.is_open()) {
			file.write(message.c_str(), message.size());
			file.write("\n", 1);
			file.close();
		}
		else {
			GRAPE_LOG_ERROR("Unable to open log file '{}' for writing.", this->log_file);
		}
	}
};