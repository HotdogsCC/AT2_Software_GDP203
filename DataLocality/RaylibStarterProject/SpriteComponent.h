#pragma once

#include "raylib.h"
#include <string>

class TransformComponent;

class SpriteComponent
{
public:
	SpriteComponent();
	SpriteComponent(std::string textureFile);

	void Draw(const Vector2 pos) const;
	void Draw(const TransformComponent transform) const;

private:
	Texture2D m_sprite;
};

