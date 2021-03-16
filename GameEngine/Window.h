#pragma once
#include <Windows.h>

namespace GameEngine {
	class Window
	{
	private:
		int width;
		int height;

		void(*update)();
		void(*events)();

		HWND wndHandle;
		WNDCLASS wndClass = {};

		static LRESULT CALLBACK StaticWndProc(HWND, UINT, WPARAM, LPARAM);
		LRESULT WndProc(UINT, WPARAM, LPARAM);

	public:
		//ctors
		Window(int, int, const wchar_t*, void(*)(), void(*)());

		//getters
		int getWidth();
		int getHeight();

		//setters
		Window &setWidth(int);
		Window &setHeight(int);
	};
}

