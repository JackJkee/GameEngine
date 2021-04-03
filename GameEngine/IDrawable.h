#pragma once
#include "Render.h"

#ifndef __DRAW__
#define __DRAW__

namespace GameObject {
	class IDrawable 
	{
	public: virtual void draw(GameEngine::RenderState & render);
	};
}

#endif // !__DRAW__