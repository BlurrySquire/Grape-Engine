#include "logger.hpp"

#include <iostream>

namespace GRAPE {
	Logger::Logger() {

	}

	void Logger::LogMessage(const std::string& message, const std::string& colour) {
		std::cout << colour << message << "\033[0m" << std::endl;
	}
};