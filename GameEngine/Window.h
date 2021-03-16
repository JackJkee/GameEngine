#pragma once
#include <Windows.h>

namespace GameEngine {
	class Window
	{
	private:
		int width;
		int height;

		void(*update)();
		void(*events)(Window*);

		HWND wndHandle;
		WNDCLASS wndClass = {};

		static LRESULT CALLBACK StaticWndProc(HWND, UINT, WPARAM, LPARAM);
		LRESULT WndProc(UINT, WPARAM, LPARAM);

		bool running;
		unsigned int message;

	public:
		//ctors
		Window(int, int, const wchar_t*, void(*update)(), void(*events)(Window*));

		//getters
		int getWidth();
		int getHeight();
		unsigned int getMessage();

		//setters
		Window &setWidth(int);
		Window &setHeight(int);
		void Close();
	};
}

