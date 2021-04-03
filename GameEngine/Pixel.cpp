#include "Window.h"
#include "Pixel.h"

GameEngine::Pixel::Pixel() { m_position.setPosition(0,0); }
GameEngine::Pixel::Pixel(GameEngine::Window* window) { m_window = window; }
GameEngine::Pixel::Pixel(GameEngine::Window* window, int x, int y) { m_window = window; m_position.setX(x); m_position.setY(y); }
GameEngine::Pixel::Pixel(GameEngine::Window* window, int x, int y, unsigned int color) { m_window = window; m_position.setX(x); m_position.setY(y); m_color = color; }

void GameEngine::Pixel::initizliseWindow(GameEngine::Window* window)
{
	m_window = window;
}

void GameEngine::Pixel::setColor(unsigned int color) { m_color = color; }
unsigned int GameEngine::Pixel::getColor() { return m_color; }

void GameEngine::Pixel::draw() {
	if (nullptr == this->m_window)
		return;

	unsigned int real_pos = m_position.getY() * m_window->getWidth() + m_position.getX();
	unsigned int* pix = (unsigned int*)m_window->get_render().memory;

	*(pix + real_pos) = getColor();
}

void GameEngine::Pixel::setPosition(Point2d<int> pos) { m_position = pos; }

void GameEngine::Pixel::setPosition(int x, int y) { m_position.setX(x); m_position.setY(y); }