#include "logger.hpp"

#include <iostream>
#include <fstream>

namespace GRAPE {
	namespace Logger {
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
			const std::string log_colours[6] = {
				"\033[97;41m",	// FATAL
				"\033[91m",		// ERROR
				"\033[93m",		// WARN
				"\033[94m",		// INFO
				"\033[92m",		// DEBUG
				"\033[37m",		// TRACE
			};

			const std::string log_prefixes[6] = {
				"[FATAL]: ",	// FATAL
				"[ERROR]: ",	// ERROR
				"[WARN]: ",		// WARN
				"[INFO]: ",		// INFO
				"[DEBUG]: ",	// DEBUG
				"[TRACE]: ",	// TRACE
			};

			std::cout << log_colours[level] << log_prefixes[level] << message << "\033[0m" << std::endl;

			std::fstream file(this->log_file, std::ios::out | std::ios::app);
			if (file.is_open()) {
				file.write(message.c_str(), message.size());
				file.write("\n", 1);
				file.close();
			}
			else {
				std::cout << "Unable to log to '" << this->log_file << "' file." << std::endl;
			}
		}
	};
};