#include "core.hpp"
#include "application.hpp"
#include "logger.hpp"

class Sandbox : public GRAPE::Application {
public:
	void Init() override {
		this->SetAppTitle("Grape Engine Sandbox");
		this->SetAppSize(800, 600);
		
		this->InitWindow(false);

		GRAPE::Logger::GetLogger().Fatal("Sandbox: {}", "Hello, World!");
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