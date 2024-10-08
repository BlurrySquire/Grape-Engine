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
	class Logger {
	private:
		Logger(const std::string& log_name);

		void LogMessage(const std::string& message, const std::string& colour);

		std::string log_file;
	public:
		inline static Logger& GetLogger() noexcept {
			static Logger self("game-log.txt");
			return self;
		}

		template <typename... ArgTypes>
		void Fatal(std::format_string<ArgTypes...> format, ArgTypes&&... args) {
			std::stringstream stream;
			stream << "[FATAL]: " << std::format(format, std::forward<ArgTypes>(args)...);
			this->LogMessage(stream.str(), "\033[97;41m");
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

		#if defined(GRAPE_DEBUG)
			template <typename... ArgTypes>
			void Debug(std::format_string<ArgTypes...> format, ArgTypes&&... args) {
				std::stringstream stream;
				stream << "[DEBUG]: " << std::format(format, std::forward<ArgTypes>(args)...);
				this->LogMessage(stream.str(), "\033[92m");
			}

			template <typename... ArgTypes>
			void Trace(std::format_string<ArgTypes...> format, ArgTypes&&... args) {
				std::stringstream stream;
				stream << "[TRACE]: " << std::format(format, std::forward<ArgTypes>(args)...);
				this->LogMessage(stream.str(), "\033[37m");
			}
		#endif
	};
}

#endif