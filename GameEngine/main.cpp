#include "GameEngine.h"

void update() {

}

void events() {

}

int main() {

	const int w = 500, h = 500;

	GameEngine::Window wnd(w, h, L"GameWindow", &update, &events);
	return 0;
}