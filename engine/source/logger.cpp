#include "logger.hpp"

#include <iostream>

namespace GRAPE {
	Logger::Logger() {

	}

	void Logger::LogMessage(const std::string& message) {
		std::cout << message << std::endl;
	}
};