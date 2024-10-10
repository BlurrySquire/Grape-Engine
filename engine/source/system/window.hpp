#ifndef HPP_GRAPEENGINE_WINDOW
#define HPP_GRAPEENGINE_WINDOW

#include <string>

#include <GLFW/glfw3.h>

#include "core.hpp"

namespace System {
	class Window {
	private:
		GLFWwindow* pWindow;
		GLFWmonitor* pMonitor;
	public:
		Window(const std::string& title, u32 width, u32 height, bool fullscreen);
		~Window();

		void Close();

		void PollEvents();

		GLFWwindow* GetWindowHandle();

		void SetSize(u32 width, u32 height);
		void SetTitle(const std::string& title);
	};
};

#endif