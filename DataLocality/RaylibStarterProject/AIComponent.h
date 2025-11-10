#pragma once

#include "raylib.h"
#include "TransformComponent.h"

class AIComponent
{
public:
	AIComponent();
	AIComponent(float patrolDistance, float speed, bool moveLaterally = true);

	void Update(TransformComponent& transform, float deltaTime);

private:
	float m_patrolDistance;
	float m_speed;
	float totalTime;
	bool m_moveLaterally;
};

