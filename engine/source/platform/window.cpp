#include "window.hpp"

static void glfw_WindowErrorCallback(int error_code, const char* description) {
	GRAPE_LOG_CRITICAL(
		"GLFW v{0}.{1}.{2} Error {3}: {4}",
		GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION,
		error_code, description
	);
}

Window::Window(const GRAPE::AppInfo& appinfo) {
	GRAPE_LOG_TRACE(
		"Window: Initializing GLFW v{0}.{1}.{2}.",
		GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION
	);

	glfwSetErrorCallback(glfw_WindowErrorCallback);

	if (!glfwInit()) {
		GRAPE_LOG_CRITICAL(
			"Window: GLFW v{0}.{1}.{2} init failed.",
			GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION
		);
	}

	GRAPE_LOG_INFO(
		"Window: GLFW v{0}.{1}.{2} init complete.",
		GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION
	);

	if (appinfo.resizable == true) {
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
	}
	else {
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	}

	GRAPE_LOG_TRACE(
		"Window: Opening {0} window '{1}' of size ({2}x{3}).",
		appinfo.resizable ? "resizable" : "non-resizable",
		appinfo.win_title,
		appinfo.win_width, appinfo.win_height
	);

	m_window = glfwCreateWindow(appinfo.win_width, appinfo.win_height, appinfo.win_title.c_str(), NULL, NULL);

	if (m_window == NULL) {
		GRAPE_LOG_CRITICAL(
			"Window: GLFW v{0}.{1}.{2} window creation failed.",
			GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION
		);
	}

	GRAPE_LOG_INFO(
		"Window: Opened window."
	);
}

Window::~Window() {
	GRAPE_LOG_TRACE("Window: Closing Window.");
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

void Window::UpdateTitle(const std::string& title) {
	glfwSetWindowTitle(m_window, title.c_str());
}

void Window::UpdateSize(const int& width, const int& height) {
	int win_width, win_height;
	glfwGetWindowSize(m_window, &win_width, &win_height);

	if (width == NULL && height != NULL) {
		glfwSetWindowSize(m_window, win_width, height);
	}
	else if (width != NULL && height == NULL) {
		glfwSetWindowSize(m_window, width, win_height);
	}
}

std::string Window::GetTitle() {
	return glfwGetWindowTitle(m_window);
}

void Window::GetSize(int* width, int* height) {
	glfwGetWindowSize(m_window, width, height);
}

void Window::SetupEvents(const EventCallbackFun& callback_func) {
	GRAPE_LOG_TRACE(
		"Window: Initialising Events System."
	);

	m_event_callback = callback_func;

	m_eventcontext = EventContext{
		.event_callback = &m_event_callback
	};

	glfwSetWindowUserPointer(m_window, &m_eventcontext);

	GRAPE_LOG_TRACE(
		"Event: Creating event of type 'NULL'."
	);

	m_event_callback.operator()(
		GRAPE::Event(GRAPE::EventType::NONE)
	);

	// Create lambdas for GLFW event callbacks.

	glfwSetWindowSizeCallback(
		m_window,
		[](GLFWwindow* window, int width, int height) {
			EventContext* context = static_cast<EventContext*>(glfwGetWindowUserPointer(window));

			GRAPE_LOG_TRACE(
				"Event: Create event of type 'Window Resize' to ({0}x{1})",
				width, height
			);

			context->event_callback->operator()(
				GRAPE::WindowResizeEvent(width, height)
			);
		}
	);

	glfwSetMouseButtonCallback(
		m_window,
		[](GLFWwindow* window, int button, int action, int mods) {
			(mods);

			EventContext* context = static_cast<EventContext*>(glfwGetWindowUserPointer(window));

			GRAPE_LOG_TRACE(
				"Event: Created event of type 'Mouse {0}', button '{1}'",
				action == GLFW_PRESS ? "Clicked" : "Released",
				button
			);

			context->event_callback->operator()(
				GRAPE::MouseClickEvent(
					static_cast<GRAPE::MouseButton>(button),
					action == GLFW_PRESS ? true : false
				)
			);
		}
	);

	glfwSetCursorPosCallback(
		m_window,
		[](GLFWwindow* window, double xpos, double ypos) {
			EventContext* context = static_cast<EventContext*>(glfwGetWindowUserPointer(window));

			GRAPE_LOG_TRACE(
				"Event: Created event of type 'Mouse Move', ({0}, {1})",
				xpos, ypos
			);

			context->event_callback->operator()(
				GRAPE::MouseMoveEvent(
					static_cast<uint32_t>(xpos),
					static_cast<uint32_t>(ypos)
				)
			);
		}
	);
}

void Window::PollEvents() {
	glfwPollEvents();

	if (glfwWindowShouldClose(m_window)) {
		glfwSetWindowShouldClose(m_window, GLFW_FALSE);

		GRAPE_LOG_TRACE(
			"Event: Creating event of type 'Window Close'."
		);

		m_event_callback.operator()(
			GRAPE::WindowCloseEvent()
		);
	}
}