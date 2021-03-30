#include "GameEngine.h"

void update(GameEngine::Window *window) {
	GameEngine::Pixel pixel;
	for (int i = 0; i < window->getWidth(); i++) {
		pixel.draw(window, i, 100, 0x00FF00);
	}
}

void events(GameEngine::Window *window) {
	unsigned int message = window->getMessage();
	if (message == WM_CLOSE || message == WM_DESTROY) {
		window->Close();
	}
}

int main() {

	const int w = 800, h = 800;

	GameEngine::Window wnd(w, h, L"GameWindow", &update, &events);
	return 0;
}
