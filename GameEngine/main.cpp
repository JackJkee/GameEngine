#include <stdio.h>
#include "GameEngine.h"

int main() {

	const int w = 500, h = 500;

	GameEngine::Window wnd(w, h);

	printf("width = %d | height = %d\n", wnd.getWidth(), wnd.getHeight());

	wnd.setWidth(250).setHeight(250);

	printf("width = %d | height = %d\n", wnd.getWidth(), wnd.getHeight());

	return 0;
}