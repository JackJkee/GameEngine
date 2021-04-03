#pragma once
#include "Render.h"
#include "Point.h"

using namespace std;

namespace GameEngine {

	class Pixel
	{
	private:
		Point2d<int> m_position;
		GameEngine::Window* m_window = nullptr;
		unsigned int m_color = 0xFFFFFF;
	public:
		Pixel();
		Pixel(GameEngine::Window* window);
		Pixel(GameEngine::Window* window, int x, int y);
		Pixel(GameEngine::Window* window, int x, int y, unsigned int color);

		void initizliseWindow(GameEngine::Window* window);

		void setPosition(Point2d<int> pos);
		void setPosition(int x, int y);

		void setColor(unsigned int color);
		unsigned int getColor();
		
		void draw();
	};
}













