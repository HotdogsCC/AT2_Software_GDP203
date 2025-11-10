#include "TransformComponent.h"

TransformComponent::TransformComponent() : m_position({0.0f, 0.0f}) {}
TransformComponent::TransformComponent(Vector2 pos) : m_position(pos) {}


void TransformComponent::SetPosition(Vector2 pos)
{
	m_position = pos;
}

Vector2 TransformComponent::GetPosition() const
{
	return m_position;
}

