#pragma once
#include <Windows.h>

namespace GameEngine {
	struct RenderState
	{
		int width, height;
		void* memory;
		BITMAPINFO bmInfo;
	};


}

