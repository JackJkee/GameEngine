#pragma once
#include "Vector.h"
#include "Render.h"

namespace GameEngine {

	class Pixel
	{
	private:
		utils::Vector2d<int> pos;
	public:
		Pixel() {}
		utils::Vector2d<int> get_pos();
		void set_pos(utils::Vector2d<int>);

		//methods

		void draw(Window* window, int x, int y, unsigned int color);
	};

}


