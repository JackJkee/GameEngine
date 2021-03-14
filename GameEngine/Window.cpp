#include "Window.h"

// Constructors
GameEngine::Window::Window(int width, int height) { this->width = width; this->height = height; }

// Getters
int GameEngine::Window::getWidth() { return this->width; }
int GameEngine::Window::getHeight() { return this->height; }

// Setters

GameEngine::Window &GameEngine::Window::setWidth(int width) { this->width = width; return *this; }
GameEngine::Window &GameEngine::Window::setHeight(int height) { this->height = height; return *this; }

