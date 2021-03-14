#pragma once
namespace GameEngine {
	class Window
	{
	private:
		int width;
		int height;
	public:
		Window(int, int);

		int getWidth();
		int getHeight();

		Window &setWidth(int);
		Window &setHeight(int);
	};
}

