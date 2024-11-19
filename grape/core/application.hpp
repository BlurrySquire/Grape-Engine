#ifndef GRAPEENGINE_CORE_APPLICATION_HPP
#define GRAPEENGINE_CORE_APPLICATION_HPP

#include "core.hpp"
#include "logger.hpp"

#include <memory>

namespace GRAPE {
	struct AppState {
		std::string title;
		u32 width, height;

		std::unique_ptr<Logger> logger;
	};

	class Application {
	private:
		AppState* _appState;

	public:
		Application(AppState* appState);

		virtual void Init();
		virtual void Exit();
	};
}

#endif