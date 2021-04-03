#include "Window.h"
#include "IDrawable.h"

// Constructors
GameEngine::Window::Window(int width, int height, const wchar_t* title, void(*update)(GameEngine::Window*), void(*events)(GameEngine::Window*)) {
	HINSTANCE hInstance = GetModuleHandle(NULL);

	this->width = width; this->height = height; 
	this->update = update; this->events = events;
	this->running = true;

	this->wndClass.lpszClassName = L"GameEngineWindowClass";
	this->wndClass.style = CS_HREDRAW | CS_VREDRAW;
	this->wndClass.lpfnWndProc = &StaticWndProc;
	RegisterClass(&this->wndClass);

	wndHandle = CreateWindowEx(wndClass.style, wndClass.lpszClassName, title, WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, width, height, NULL, NULL, hInstance, this);
	wndContext = GetDC(wndHandle);

	while (running) {
		MSG message;
		while (PeekMessage(&message, wndHandle, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}		

		if (NULL != update)
			update(this);


		StretchDIBits(wndContext, 0, 0, render.width, render.height, 0, 0, 
										render.width, render.height, 
										render.memory, &render.bmInfo, 
										DIB_RGB_COLORS, SRCCOPY);
	}
}

// Getters
int GameEngine::Window::getWidth() { return this->width; }
int GameEngine::Window::getHeight() { return this->height; }
unsigned int GameEngine::Window::getMessage() { return this->message; }

// Setters

GameEngine::Window &GameEngine::Window::setWidth(int width) { this->width = width; return *this; }
GameEngine::Window &GameEngine::Window::setHeight(int height) { this->height = height; return *this; }

void GameEngine::Window::draw(GameObject::IDrawable& object)
{
	object.draw(render);
}

void GameEngine::Window::Close() { running = false; }


//WinProcess in class
LRESULT GameEngine::Window::WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	// После каждого изменения размера экрана (в том числе и при открытии экрана)
	// Резервируем и выделяем память для работы с теми пикселями, где расположено наше окно.
	if (uMsg == WM_SIZE) {
		RECT rect; 
		GetClientRect(wndHandle, &rect);
		render.width = rect.right - rect.left;
		render.height = rect.bottom - rect.top;

		this->width = render.width;
		this->height = render.height;
		
		// sizeof(unsigned int) = 4 byte. Умножаем на него, чтобы иметь место в памяти для каждого цвета RGB
		// 1 цвет = 1 байт. Тип цвета unsigned char или BYTE. Они идут в порядке не Red Green Blue,
		// а Blue Green Red и еще добавляется Reserved.
		// Поэтому мы могли просто дамножить на sizeof(BYTE*4) или просто на 4
		int buffer_size = render.width * render.height * sizeof(unsigned int); 

		if (render.memory) VirtualFree(render.memory, 0, MEM_RELEASE);
		render.memory = VirtualAlloc(0, buffer_size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

		render.bmInfo.bmiHeader.biSize = sizeof(render.bmInfo.bmiHeader);
		render.bmInfo.bmiHeader.biWidth = render.width;
		render.bmInfo.bmiHeader.biHeight = render.height;
		render.bmInfo.bmiHeader.biPlanes = 1;
		render.bmInfo.bmiHeader.biBitCount = 32;
		render.bmInfo.bmiHeader.biCompression = BI_RGB;
	}
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


