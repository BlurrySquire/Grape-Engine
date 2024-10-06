#include "core.hpp"

#include "application.hpp"

class Sandbox : public GRAPE::Application {
public:
	void Init() override {
		this->SetAppTitle("Grape Engine Sandbox");
		this->SetAppSize(800, 600);
		
		this->InitWindow(false);
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