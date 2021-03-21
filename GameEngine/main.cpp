#include "GameEngine.h"

void update(GameEngine::Window *window) {

	
}

void events(GameEngine::Window *window) {
	unsigned int message = window->getMessage();
	if (message == WM_CLOSE || message == WM_DESTROY) {
		window->Close();
	}
}

int main() {

	const int w = 500, h = 500;

	GameEngine::Window wnd(w, h, L"GameWindow", &update, &events);
	return 0;
}