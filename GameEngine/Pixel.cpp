#include "Window.h"
#include "Pixel.h"

utils::Vector2d<int> GameEngine::Pixel::get_pos()
{
    return this->pos;
}

void GameEngine::Pixel::set_pos(utils::Vector2d<int> new_pos) {
    this->pos = new_pos;
}

void GameEngine::Pixel::draw(GameEngine::Window* window, int x, int y, unsigned int color)
{
    int w = window->getWidth();
    unsigned int* pixel = (unsigned int*)window->get_render().memory;
    *(pixel + w * y + x) = color;
}

