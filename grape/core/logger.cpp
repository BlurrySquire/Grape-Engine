#include "logger.hpp"

namespace GRAPE {
	std::shared_ptr<spdlog::logger> Logger::pLogger;

	Logger::Logger(const std::string& log_name) {
		spdlog::level::level_enum level = spdlog::level::trace;
		#if defined(GRAPE_BUILD_RELEASE)
			level = spdlog::level::info;
		#endif

		auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
		auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(log_name + std::string(".log"), true);
		spdlog::sinks_init_list sink_list = { file_sink, console_sink };

		spdlog::logger logger(log_name, sink_list.begin(), sink_list.end());
		logger.set_level(level);
		logger.set_pattern("%^%L: %v%$");

		this->pLogger = std::make_shared<spdlog::logger>(logger);
		spdlog::set_default_logger(this->pLogger);
	}
} // GRAPE