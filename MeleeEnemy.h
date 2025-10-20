#pragma once

#include <iostream>
#include "Enemy.h"

class MeleeEnemy : public Enemy
{
public:
	MeleeEnemy()
	{
		std::cout << "Melee Enemy Created " << '\n';
	}

	MeleeEnemy(std::string name, Vector2 position) : Enemy(name, position)
	{
		std::cout << "Melee enemy created with name and pos" << '\n';
	}

	void update(float) override
	{
		
	}

	void draw() override
	{
		DrawCircleV(m_position, 25.0f, SKYBLUE);
	}
};