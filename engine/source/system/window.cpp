#include "window.hpp"

#include "logger.hpp"

namespace System {
	Window::Window(const std::string& title, u32 width, u32 height, bool fullscreen) {
		if (!glfwInit()) {
			GRAPE_LOG_FATAL(
				"GLFW Backend: Failed to init - {}.",
				glfwGetError(nullptr)
			);

			return;
		}

		this->pMonitor = glfwGetPrimaryMonitor();

		if (fullscreen) {
			this->pWindow = glfwCreateWindow(
				width, height,
				title.c_str(),
				this->pMonitor,
				nullptr
			);
		}
		else {
			this->pWindow = glfwCreateWindow(
				width, height, title.c_str(),
				nullptr,
				nullptr
			);
		}

		if (this->pWindow == nullptr) {
			GRAPE_LOG_FATAL(
				"GLFW Backend: Failed to open a window - {}.",
				glfwGetError(nullptr)
			);

			return;
		}
	}

	Window::~Window() {

	}

	void Window::Close() {
		glfwDestroyWindow(this->pWindow);
		glfwTerminate();
	}

	void Window::PollEvents() {
		glfwPollEvents();
	}

	GLFWwindow* Window::GetWindowHandle() {
		return this->pWindow;
	}

	void Window::SetSize(u32 width, u32 height) {
		glfwSetWindowSize(this->pWindow, width, height);
	}

	void Window::SetTitle(const std::string& title) {
		glfwSetWindowTitle(this->pWindow, title.c_str());
	}
}