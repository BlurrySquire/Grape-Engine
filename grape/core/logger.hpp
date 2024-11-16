#ifndef GRAPEENGINE_CORE_LOGGER_HPP
#define GRAPEENGINE_CORE_LOGGER_HPP

#include <memory>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

#define GRAPE_LOG_CRITICAL(...) GRAPE::Logger::GetLogger()->critical(__VA_ARGS__)
#define GRAPE_LOG_ERROR(...) GRAPE::Logger::GetLogger()->error(__VA_ARGS__)
#define GRAPE_LOG_WARN(...) GRAPE::Logger::GetLogger()->warn(__VA_ARGS__)
#define GRAPE_LOG_INFO(...) GRAPE::Logger::GetLogger()->info(__VA_ARGS__)
#define GRAPE_LOG_DEBUG(...) GRAPE::Logger::GetLogger()->debug(__VA_ARGS__)
#define GRAPE_LOG_TRACE(...) GRAPE::Logger::GetLogger()->trace(__VA_ARGS__)

namespace GRAPE {
	class Logger {
	private:
		static std::shared_ptr<spdlog::logger> pLogger;
	public:
		Logger(const std::string& log_name);

		inline static std::shared_ptr<spdlog::logger>& GetLogger() {
			return pLogger;
		}
	};
} // GRAPE

#endif