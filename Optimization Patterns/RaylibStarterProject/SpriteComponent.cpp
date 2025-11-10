#include "SpriteComponent.h"

SpriteComponent::SpriteComponent() = default;

SpriteComponent::SpriteComponent(std::string textureFile)
{
	m_sprite = LoadTexture(textureFile.c_str());
}

void SpriteComponent::Draw(const Vector2 pos) const
{
	DrawTexture(m_sprite, pos.x, pos.y, WHITE);
}

