#pragma once

#include "raylib.h"

class MoveableComponent
{
public:
	MoveableComponent(float speed);

	void Update(Vector2 position);

	Vector2 GetPosition() const;

private:
	float m_speed = 0.0f;
	Vector2 m_position;
};

