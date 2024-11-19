#include <grape/core/core.hpp>
#include <grape/core/logger.hpp>
#include <grape/core/application.hpp>

#include <iostream>

GRAPE::AppConfig app_config = {
	.title = "Grape-Engine Sandbox",
	.width = 800,
	.height = 600
};

class Sandbox : public GRAPE::Application {
	using GRAPE::Application::Application;

public:
	void Init() override {
		GRAPE_LOG_INFO("Sandbox init.");
	}

	void Exit() override {
		GRAPE_LOG_INFO("Sandbox exit.");
	}
};

int app_entry([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	GRAPE_LOG_INFO("Hello, World!");

	Sandbox sandbox(&app_config);
	sandbox.Init();
	sandbox.Exit();

	return 0;
}