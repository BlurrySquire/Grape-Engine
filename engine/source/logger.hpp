#ifndef HPP_GRAPEENGINE_LOGGER
#define HPP_GRAPEENGINE_LOGGER

#include <iostream>
#include <sstream>
#include <string>
#include <format>

namespace GRAPE {
	class Logger {
	private:
		Logger();

		void LogMessage(const std::string& message, const std::string& colour);
	public:
		inline static Logger& GetLogger() {
			static Logger self{};
			return self;
		}

		template <typename... ArgTypes>
		void Fatal(std::format_string<ArgTypes...> format, ArgTypes&&... args) {
			std::stringstream stream;
			stream << "[FATAL]: " << std::format(format, std::forward<ArgTypes>(args)...);
			this->LogMessage(stream.str(), "\033[37;41m");
		}

		template <typename... ArgTypes>
		void Error(std::format_string<ArgTypes...> format, ArgTypes&&... args) {
			std::stringstream stream;
			stream << "[ERROR]: " << std::format(format, std::forward<ArgTypes>(args)...);
			this->LogMessage(stream.str(), "\033[31m");
		}

		template <typename... ArgTypes>
		void Warn(std::format_string<ArgTypes...> format, ArgTypes&&... args) {
			std::stringstream stream;
			stream << "[WARN]: " << std::format(format, std::forward<ArgTypes>(args)...);
			this->LogMessage(stream.str(), "\033[33m");
		}

		template <typename... ArgTypes>
		void Info(std::format_string<ArgTypes...> format, ArgTypes&&... args) {
			std::stringstream stream;
			stream << "[INFO]: " << std::format(format, std::forward<ArgTypes>(args)...);
			this->LogMessage(stream.str(), "\033[36m");
		}
	};
}

#endif