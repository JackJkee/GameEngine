#pragma once
#include "IDrawable.h"

namespace GameObject {
	class Line : public IDrawable
	{
	public: void draw(GameEngine::RenderState& render) override;
	};
}

