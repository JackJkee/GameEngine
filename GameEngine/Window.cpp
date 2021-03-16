#include "Window.h"

// Constructors
GameEngine::Window::Window(int width, int height, const wchar_t* title, void(*update)(), void(*events)(GameEngine::Window*)) {
	HINSTANCE hInstance = GetModuleHandle(NULL);

	this->width = width; this->height = height; 
	this->update = update; this->events = events;
	this->running = true;

	this->wndClass.lpszClassName = L"GameEngineWindowClass";
	this->wndClass.style = CS_HREDRAW | CS_VREDRAW;
	this->wndClass.lpfnWndProc = &StaticWndProc;
	RegisterClass(&this->wndClass);
	wndHandle = CreateWindowEx(wndClass.style, wndClass.lpszClassName, title, WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, width, height, NULL, NULL, hInstance, this);

	

	while (running) {
		MSG message;
		while (PeekMessage(&message, wndHandle, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		if (NULL != update)
			update();
	}
}

// Getters
int GameEngine::Window::getWidth() { return this->width; }
int GameEngine::Window::getHeight() { return this->height; }
unsigned int GameEngine::Window::getMessage() { return this->message; }

// Setters

GameEngine::Window &GameEngine::Window::setWidth(int width) { this->width = width; return *this; }
GameEngine::Window &GameEngine::Window::setHeight(int height) { this->height = height; return *this; }
void GameEngine::Window::Close() { running = false; }

//WinProcess in class
LRESULT GameEngine::Window::WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (events != NULL) {
		this->message = uMsg;
		events(this);
	}		
	return DefWindowProc(wndHandle, uMsg, wParam, lParam);
}

//Static WinProcess
LRESULT GameEngine::Window::StaticWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	GameEngine::Window* self;

	if (uMsg == WM_NCCREATE) {
		LPCREATESTRUCT lpcs = reinterpret_cast<LPCREATESTRUCT>(lParam);
		self = static_cast<GameEngine::Window*>(lpcs->lpCreateParams);
		self->wndHandle = hwnd;
		SetWindowLongPtr(hwnd, GWLP_USERDATA,
			reinterpret_cast<LONG_PTR>(self));
	}
	else {
		self = reinterpret_cast<GameEngine::Window*>(
			GetWindowLongPtr(hwnd, GWLP_USERDATA));
	}
	if (self) {
		return self->WndProc(uMsg, wParam, lParam);
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


