#pragma once

#include "raylib.h"

class TransformComponent
{
public:
	TransformComponent(); 
	TransformComponent(Vector2 pos); 

	Vector2 GetPosition() const;
	void SetPosition(Vector2 pos);

private:
	Vector2 m_position;
};