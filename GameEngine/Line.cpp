#include "Line.h"


void GameObject::Line::draw(GameEngine::RenderState& render)
{
	unsigned int* pixels = (unsigned int*) render.memory;

	int w = render.width;
	int h = render.height;
	int y = 150;
	for (int i = 0; i < w; i++) {
		*(pixels + y * w + i) = 0xff00ff;
	}
}
