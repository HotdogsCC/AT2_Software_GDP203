#pragma once

#include "raylib.h"
#include <string>

class SpriteComponent
{
public:
	SpriteComponent();
	SpriteComponent(std::string textureFile);

	void Draw(const Vector2 pos) const;

private:
	Texture2D m_sprite;
};

