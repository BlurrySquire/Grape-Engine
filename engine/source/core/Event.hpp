#pragma once

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
	};

	class WindowCloseEvent : Event {
	public:
		inline WindowCloseEvent() {
			m_type = EventType::WINDOW_CLOSE;
			m_handled = false;
		}
	};

	class WindowResizeEvent : Event {
	public:
		inline WindowResizeEvent(uint32_t width, uint32_t height) {
			m_type = EventType::WINDOW_RESIZE;
			m_handled = false;
		}
	};
}