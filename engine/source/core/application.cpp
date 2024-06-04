#include "application.hpp"

namespace GRAPE {
	Application::Application(const AppInfo& appinfo)
	: m_appinfo(appinfo), m_logger("grape-engine_log"), m_window(appinfo) {
		GRAPE_LOG_INFO("Application: Init complete.");
	}

	Application::~Application() {
	}

	void Application::HandleEvents(const GRAPE::Event& event) {
		switch (event.type) {
			case GRAPE::EventType::NONE: {
				GRAPE_LOG_INFO(
					"Application: Event received of type 'NULL'."
				);
			} break;

			case EventType::WINDOW_CLOSE: {
				GRAPE_LOG_INFO(
					"Application: Event received of type 'Window Close'."
				);
				m_isrunning = false;
			} break;

			case EventType::WINDOW_RESIZE: {
				WindowResizeEvent local_event = static_cast<const WindowResizeEvent&>(event);

				GRAPE_LOG_INFO(
					"Application: Event received of type 'Window Resize' to ({0}x{1})",
					local_event.width, local_event.height
				);

				m_appinfo.win_width = local_event.width;
				m_appinfo.win_height = local_event.height;
				m_window.UpdateSize(local_event.width, local_event.height);
			} break;

			case EventType::MOUSE_CLICK: {
				MouseClickEvent local_event = static_cast<const MouseClickEvent&>(event);

				GRAPE_LOG_INFO(
					"Application: Event received of type 'Mouse {0}', Button '{1}'",
					local_event.click ? "Click" : "Release",
					static_cast<int>(local_event.button)
				);
			} break;

			case EventType::MOUSE_MOVE: {
				MouseMoveEvent local_event = static_cast<const MouseMoveEvent&>(event);

				GRAPE_LOG_INFO(
					"Application: Event Received of type 'Mouse Move', ({0}, {1})",
					local_event.mouse_x,
					local_event.mouse_y
				);
			} break;
		}
	}

	void Application::Run() {
		GRAPE_LOG_INFO("Application: Main loop started.");

		m_window.SetupEvents([this](const GRAPE::Event& ev) { this->HandleEvents(ev); });

		m_isrunning = true;
		while (m_isrunning) {
			m_window.PollEvents();
		}

		GRAPE_LOG_INFO("Application: Main loop exited.");
	}

	void Application::TimeSleep(const uint32_t milliseconds) {
		Platform::Time_Sleep(milliseconds);
	}

	SystemTime Application::GetLocalTime() {
		return Platform::Time_GetLocal();
	}

	SystemDate Application::GetLocalDate() {
		return Platform::Time_GetDate();
	}

	std::string Application::GetWinTitle() {
		return m_window.GetTitle();
	}

	void Application::GetWinSize(int* width, int* height) {
		return m_window.GetSize(width, height);
	}

	void Application::UpdateWinTitle(const std::string& title) {
		m_appinfo.win_title = title;
		m_window.UpdateTitle(title);
	}

	void Application::UpdateWinSize(const int& width, const int& height) {
		if (width == NULL && height != NULL) {
			m_appinfo.win_height = height;
		}
		else if (width != NULL && height == NULL) {
			m_appinfo.win_width = width;
		}

		m_window.UpdateSize(width, height);
	}

	AppInfo Application::GetApplicationInfo() {
		return m_appinfo;
	}
}