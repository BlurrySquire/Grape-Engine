#ifndef HPP_GRAPEENGINE_APPLICATION
#define HPP_GRAPEENGINE_APPLICATION

#include <string>

#include "core.hpp"

// Forward declare window class
namespace System {
	class Window;
}

namespace GRAPE {
	class Application {
	private:
		std::string pAppTitle;
		u32 pAppWidth, pAppHeight;
		bool pRunning;

		System::Window* pWindow;
	public:
		Application();
		~Application();

		void InitWindow(bool fullscreen);
		void ExitWindow();

		void Run();
		void ExitMainLoop();

		virtual void Init();
		virtual void Exit();

		virtual void OnKeyPress();
		virtual void OnMouseMove();
		virtual void OnMouseDown();
		virtual void OnWindowClose();

		virtual void OnUpdateFrame();
		virtual void OnRenderFrame();

		System::Window* GetWindow();

		void SetAppTitle(const std::string& title);
		void SetAppWidth(u32 width);
		void SetAppHeight(u32 height);
		void SetAppSize(u32 width, u32 height);
	};
};

#endif