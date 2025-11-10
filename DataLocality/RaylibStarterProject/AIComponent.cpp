#include "AIComponent.h"

#include "raymath.h"

AIComponent::AIComponent() = default;
AIComponent::AIComponent(float patrolDistance, float speed, bool moveLaterally) :
	m_patrolDistance(patrolDistance), m_speed(speed), m_moveLaterally(moveLaterally), totalTime(0.0f) {}

void AIComponent::Update(TransformComponent& transform, float deltaTime)
{
	totalTime += deltaTime;

	Vector2 pos = transform.GetPosition();

	if (m_moveLaterally)
	{
		pos.x = transform.GetPosition().x + m_patrolDistance * cos(totalTime) * m_speed * deltaTime;
	}
	else
	{
		pos.y = transform.GetPosition().y + m_patrolDistance * cos(totalTime) * m_speed * deltaTime;
	}

	transform.SetPosition(pos);
}


