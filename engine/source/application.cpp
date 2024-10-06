#include "application.hpp"

#include "system/window.hpp"

namespace GRAPE {
	Application::Application() {
		this->pAppTitle = "Grape Engine Application";
		this->pAppWidth = 800;
		this->pAppHeight = 600;

		this->pWindow = nullptr;

		this->pRunning = false;
	}

	Application::~Application() {
		delete this->pWindow;
	}

	void Application::InitWindow(bool fullscreen) {
		if (this->pWindow == nullptr) {
			this->pWindow = new System::Window(
				this->pAppTitle,
				this->pAppWidth, this->pAppHeight,
				fullscreen
			);
		}
		else {
			// log something
		}
	}

	void Application::ExitWindow() {
		if (this->pWindow != nullptr) {
			this->pWindow->Close();
			delete this->pWindow;
			this->pWindow = nullptr;
		}
		else {
			// log something
		}
	}

	void Application::Run() {
		if (this->pRunning == false) {
			this->pRunning = true;

			while (this->pRunning) {
				this->pWindow->PollEvents();
				this->OnUpdateFrame();
				this->OnRenderFrame();
			}
		}
		else {
			// Log something
		}
	}

	void Application::ExitMainLoop() {
		if (this->pRunning == true) {
			this->pRunning = false;
		}
		else {
			// Log something
		}
	}

	void Application::Init() {
		this->InitWindow(false);
	}

	void Application::Exit() {
		this->ExitWindow();
	}

	void Application::OnKeyPress() {
		// TODO: EVENTS
	}

	void Application::OnMouseMove() {
		// TODO: EVENTS
	}

	void Application::OnMouseDown() {
		// TODO: EVENTS
	}

	void Application::OnWindowClose() {
		// TODO: EVENTS
	}

	void Application::OnUpdateFrame() {
		// TODO RENDERING
	}

	void Application::OnRenderFrame() {
		// TODO RENDERING
	}

	System::Window* Application::GetWindow() {
		return this->pWindow;
	}

	void Application::SetAppTitle(const std::string& title) {
		this->pAppTitle = title;

		if (this->pWindow != nullptr) {
			this->pWindow->SetTitle(this->pAppTitle);
		}
		else {
			// log something
		}
	}

	void Application::SetAppSize(u32 width, u32 height) {
		this->pAppWidth = width;
		this->pAppHeight = height;

		if (this->pWindow != nullptr) {
			this->pWindow->SetSize(this->pAppWidth, this->pAppHeight);
		}
		else {
			// log something
		}
	}

	void Application::SetAppWidth(u32 width) {
		this->pAppWidth = width;

		if (this->pWindow != nullptr) {
			this->pWindow->SetSize(this->pAppWidth, this->pAppHeight);
		}
		else {
			// log something
		}
	}

	void Application::SetAppHeight(u32 height) {
		this->pAppHeight = height;

		if (this->pWindow != nullptr) {
			this->pWindow->SetSize(this->pAppWidth, this->pAppHeight);
		}
		else {
			// log something
		}
	}
};