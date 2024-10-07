#include "core.hpp"
#include "application.hpp"
#include "logger.hpp"

class Sandbox : public GRAPE::Application {
public:
	void Init() override {
		this->SetAppTitle("Grape Engine Sandbox");
		this->SetAppSize(800, 600);
		
		this->InitWindow(false);

		GRAPE::Logger::GetLogger().Fatal("Testing");
		GRAPE::Logger::GetLogger().Error("Testing");
		GRAPE::Logger::GetLogger().Warn("Testing");
		GRAPE::Logger::GetLogger().Info("Testing");
		GRAPE::Logger::GetLogger().Trace("Testing");
		GRAPE::Logger::GetLogger().Debug("Testing");
	}

	void Exit() override {
		this->ExitWindow();
	}
};

int main() {
	Sandbox sandbox;
	sandbox.Init();
	sandbox.Run();
	return 0;
}