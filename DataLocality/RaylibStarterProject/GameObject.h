#pragma once

#include "TransformComponent.h"
#include "MoveableComponent.h"
#include "SpriteComponent.h"

class GameObject
{
public:
	GameObject(TransformComponent* transform, MoveableComponent* moveable, SpriteComponent* sprite);
	~GameObject();

	void Update();
	void Draw();

private:
	TransformComponent* m_transform;
	MoveableComponent* m_moveable;
	SpriteComponent* m_sprite;

};

