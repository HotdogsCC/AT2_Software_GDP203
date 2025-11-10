#include "MoveableComponent.h"

MoveableComponent::MoveableComponent(float speed) : m_speed(speed) {}

void MoveableComponent::Update(Vector2 position)
{
	if (IsKeyDown(KEY_A))
	{
		position.x -= m_speed;
	}

	if (IsKeyDown(KEY_D))
	{
		position.x += m_speed; 
	}

	if (IsKeyDown(KEY_W))
	{
		position.y -= m_speed;
	}

	if (IsKeyDown(KEY_S))
	{
		position.y += m_speed;
	}

	m_position = position;
}


Vector2 MoveableComponent::GetPosition() const
{
	return m_position;
}
