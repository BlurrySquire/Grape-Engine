#include "logger.hpp"

#include <iostream>

namespace GRAPE {
	Logger::Logger(const std::string& log_name) {
		(log_name);
	}

	void Logger::LogMessage(const std::string& message, const std::string& colour) {
		std::cout << colour << message << "\033[0m" << std::endl;
	}
};