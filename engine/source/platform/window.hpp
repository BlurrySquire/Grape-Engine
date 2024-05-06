#pragma once

#include <string>

#include "../defines.hpp"
#include "../core/logger.hpp"
#include "../core/Event.hpp"

#include <GLFW/glfw3.h>

using EventCallbackFun = std::function<void(const GRAPE::Event&)>;

class Window {
private:
	GLFWwindow* m_window;
	EventCallbackFun m_event_callback = NULL;
public:
	Window(const GRAPE::AppInfo& appinfo);
	~Window();

	void UpdateTitle(const std::string& title);
	void UpdateSize(const int& width, const int& height);

	std::string GetTitle();
	void GetSize(int* width, int* height);

	void SetupEvents(const std::function<void(const GRAPE::Event& event)>& callback_func);
	void PollEvents();
};