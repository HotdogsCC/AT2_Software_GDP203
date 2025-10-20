#pragma once

#include <iostream>
#include "IEnemy.h"

class GoblinMelee : public IEnemy
{
public:
	GoblinMelee()
	{
		std::cout << "melee enemy created" << '\n';
	}

	GoblinMelee(std::string name, Vector2 position) : IEnemy(name, position)
	{
		std::cout << "melee enemy created with name and position" << '\n';
	}

	virtual IEnemy* clone() override
	{
		return new GoblinMelee(m_name, m_position);
	}

	void update(float) override
	{
		
	}

	void draw() override
	{
		DrawCircleV(m_position, m_radius, m_colour);
	}
};