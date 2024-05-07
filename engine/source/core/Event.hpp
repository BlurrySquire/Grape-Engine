#pragma once

#include <GLFW/glfw3.h>

namespace GRAPE {
	enum class EventType {
		NONE = 0,
		WINDOW_CLOSE = 1,
		WINDOW_RESIZE = 2,
		KEYBOARD_KEY_DOWN = 3,
		KEYBOARD_KEY_UP = 4,
		MOUSE_MOVE = 5,
		MOUSE_DOWN = 6,
	};

	class Event {
	public:
		EventType m_type;
		bool m_handled;

		inline Event(const EventType& type) {
			m_type = type;
			m_handled = false;
		}
	};

	class WindowCloseEvent : public Event {
	public:
		inline WindowCloseEvent()
		: Event(EventType::WINDOW_CLOSE) {
		}
	};

	class WindowResizeEvent : public Event {
	public:
		uint32_t m_width, m_height;

		inline WindowResizeEvent(uint32_t width, uint32_t height)
		: Event(EventType::WINDOW_RESIZE) {

			m_width = width;
			m_height = height;
		}
	};

	enum class Mouse {
		LEFT = GLFW_MOUSE_BUTTON_LEFT,
		MIDDLE = GLFW_MOUSE_BUTTON_MIDDLE,
		RIGHT = GLFW_MOUSE_BUTTON_RIGHT
	};
}