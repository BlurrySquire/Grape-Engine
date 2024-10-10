#ifndef HPP_GRAPEENGINE_LOGGER
#define HPP_GRAPEENGINE_LOGGER

#include <string>
#include <format>

namespace GRAPE {
	namespace Logger {
		enum LogLevel {
			FATAL = 0,
			ERROR = 1,
			WARN = 2,
			INFO = 3,
			DEBUG = 4,
			TRACE = 5
		};

		class Logger {
		private:

			std::string log_file = "game-log.txt";
		public:
			Logger() = default;

			void LogMessage(const std::string& message, LogLevel level);

			static Logger& GetLogger();

			void SetLogFile(const std::string& filepath);
			void ClearLogFile();
		};
	};
}

#define GRAPE_LOG_FATAL(fmt_str, ...) \
	GRAPE::Logger::Logger::GetLogger().LogMessage( \
		std::format(fmt_str, __VA_ARGS__), \
		GRAPE::Logger::LogLevel::FATAL \
	)

#define GRAPE_LOG_ERROR(fmt_str, ...) \
	GRAPE::Logger::Logger::GetLogger().LogMessage( \
		std::format(fmt_str, __VA_ARGS__), \
		GRAPE::Logger::LogLevel::ERROR \
	)

#define GRAPE_LOG_WARN(fmt_str, ...) \
	GRAPE::Logger::Logger::GetLogger().LogMessage( \
		std::format(fmt_str, __VA_ARGS__), \
		GRAPE::Logger::LogLevel::WARN \
	)

#define GRAPE_LOG_INFO(fmt_str, ...) \
	GRAPE::Logger::Logger::GetLogger().LogMessage( \
		std::format(fmt_str, __VA_ARGS__), \
		GRAPE::Logger::LogLevel::INFO \
	)

#define GRAPE_LOG_DEBUG(fmt_str, ...) \
	GRAPE::Logger::Logger::GetLogger().LogMessage( \
		std::format(fmt_str, __VA_ARGS__), \
		GRAPE::Logger::LogLevel::DEBUG \
	)

#define GRAPE_LOG_TRACE(fmt_str, ...) \
	GRAPE::Logger::Logger::GetLogger().LogMessage( \
		std::format(fmt_str, __VA_ARGS__), \
		GRAPE::Logger::LogLevel::TRACE \
	)

#define GRAPE_ASSERT(value, format, ...) \
	if (!(value)) { \
		GRAPE::Logger::Logger::GetLogger().LogMessage( \
			std::format(fmt_str, __VA_ARGS__), \
			GRAPE::Logger::LogLevel::TRACE \
		); \
		exit(-1); \
	}

#endif