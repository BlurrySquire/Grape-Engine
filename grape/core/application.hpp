#ifndef GRAPEENGINE_CORE_APPLICATION_HPP
#define GRAPEENGINE_CORE_APPLICATION_HPP

#include "core.hpp"

namespace GRAPE {
	struct AppConfig {
		std::string title;
		u32 width, height;
	};

	class Application {
	private:
		AppConfig* _appConfig;

	public:
		Application(AppConfig* appConfig);

		virtual void Init();
		virtual void Exit();
	};
}

#endif