#include "core.hpp"
#include "application.hpp"
#include "logger.hpp"

class Sandbox : public GRAPE::Application {
public:
	void Init() override {
		this->SetAppTitle("Grape Engine Sandbox");
		this->SetAppSize(800, 600);
		
		this->InitWindow(false);

		GRAPE_LOG_FATAL("Testing");
		GRAPE_LOG_ERROR("Testing");
		GRAPE_LOG_WARN("Testing");
		GRAPE_LOG_INFO("Testing");
		GRAPE_LOG_DEBUG("Testing");
		GRAPE_LOG_TRACE("Testing");

		// Asserts kill the process.
		// bool assert_test = false;
		// GRAPE_ASSERT(assert_test == true, "'assert_test == true' failed.");
	}

	void Exit() override {
		this->ExitWindow();
	}
};

int main() {
	// This needs to be done first.
	GRAPE::Logger::Logger::GetLogger().SetLogFile("test-log.txt");
	GRAPE::Logger::Logger::GetLogger().ClearLogFile();

	Sandbox sandbox;
	sandbox.Init();
	sandbox.Run();
	return 0;
}