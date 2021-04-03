#include "GameEngine.h"
#include "GameObject.h"
#include <cstdlib>
#include <vector>
#include <time.h>
#include <chrono>

using namespace GameEngine;
using namespace std::chrono;

GameObject::Line line;

void update(GameEngine::Window *window) {
	window->draw(line);
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
