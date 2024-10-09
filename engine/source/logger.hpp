#ifndef HPP_GRAPEENGINE_LOGGER
#define HPP_GRAPEENGINE_LOGGER

#include <sstream>
#include <string>
#include <format>

#define GRAPE_LOG_FATAL(format, ...) GRAPE::Logger::GetLogger().Fatal(format, __VA_ARGS__);
#define GRAPE_LOG_ERROR(format, ...) GRAPE::Logger::GetLogger().Error(format, __VA_ARGS__);
#define GRAPE_LOG_WARN(format, ...) GRAPE::Logger::GetLogger().Warn(format, __VA_ARGS__);
#define GRAPE_LOG_INFO(format, ...) GRAPE::Logger::GetLogger().Info(format, __VA_ARGS__);
#define GRAPE_LOG_TRACE(format, ...) GRAPE::Logger::GetLogger().Trace(format, __VA_ARGS__);

#define GRAPE_ASSERT(value, format, ...) \
	if (!(value)) { GRAPE::Logger::GetLogger().Fatal(format, __VA_ARGS__); }

#if defined(GRAPE_DEBUG)
	#define GRAPE_LOG_DEBUG(format, ...) GRAPE::Logger::GetLogger().Debug(format, __VA_ARGS__);
	#define GRAPE_LOG_TRACE(format, ...) GRAPE::Logger::GetLogger().Trace(format, __VA_ARGS__);
#else defined(GRAPE_RELEASE)
	#define GRAPE_LOG_DEBUG(format, ...)
	#define GRAPE_LOG_TRACE(format, ...)
#endif

namespace GRAPE {
	enum LogLevel {
		NONE = 0,
		FATAL = 1,
		ERROR = 2,
		WARN = 3,
		INFO = 4,
		DEBUG = 5,
		TRACE = 6
	};

	class Logger {
	private:
		void LogMessage(const std::string& message, LogLevel level);

		std::string log_file = "game-log.txt";
	public:
		Logger() = default;

		static Logger& GetLogger();

		void SetLogFile(const std::string& filepath);
		void ClearLogFile();

		template <typename... ArgTypes>
		void Fatal(std::format_string<ArgTypes...> format, ArgTypes&&... args) {
			std::stringstream stream;
			stream << "[FATAL]: " << std::format(format, std::forward<ArgTypes>(args)...);
			this->LogMessage(stream.str(), LogLevel::FATAL);
		}

		template <typename... ArgTypes>
		void Error(std::format_string<ArgTypes...> format, ArgTypes&&... args) {
			std::stringstream stream;
			stream << "[ERROR]: " << std::format(format, std::forward<ArgTypes>(args)...);
			this->LogMessage(stream.str(), LogLevel::ERROR);
		}

		template <typename... ArgTypes>
		void Warn(std::format_string<ArgTypes...> format, ArgTypes&&... args) {
			std::stringstream stream;
			stream << "[WARN]: " << std::format(format, std::forward<ArgTypes>(args)...);
			this->LogMessage(stream.str(), LogLevel::WARN);
		}

		template <typename... ArgTypes>
		void Info(std::format_string<ArgTypes...> format, ArgTypes&&... args) {
			std::stringstream stream;
			stream << "[INFO]: " << std::format(format, std::forward<ArgTypes>(args)...);
			this->LogMessage(stream.str(), LogLevel::INFO);
		}

		#if defined(GRAPE_DEBUG)
			template <typename... ArgTypes>
			void Debug(std::format_string<ArgTypes...> format, ArgTypes&&... args) {
				std::stringstream stream;
				stream << "[DEBUG]: " << std::format(format, std::forward<ArgTypes>(args)...);
				this->LogMessage(stream.str(), LogLevel::DEBUG);
			}

			template <typename... ArgTypes>
			void Trace(std::format_string<ArgTypes...> format, ArgTypes&&... args) {
				std::stringstream stream;
				stream << "[TRACE]: " << std::format(format, std::forward<ArgTypes>(args)...);
				this->LogMessage(stream.str(), LogLevel::TRACE);
			}
		#endif
	};
}

#endif