#pragma once

#include <iostream>
#include "Enemy.h"

class HeavyEnemy : public Enemy
{
public:
	HeavyEnemy()
	{
		std::cout << "Heavy enemy created" << '\n';
	}

	HeavyEnemy(std::string name, Vector2 position) : Enemy(name, position)
	{
		std::cout << "Heavy enemy created with name and pos" << '\n';
	}

	void update(float) override
	{
		
	}

	void draw() override
	{
		DrawCircleV(m_position, 50, DARKBLUE);
	}
};