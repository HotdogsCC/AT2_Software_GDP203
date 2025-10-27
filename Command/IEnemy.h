#pragma once

#include <string>
#include "raylib.h"

using Colour = Color;

//enemy interface
class IEnemy
{
public:
	IEnemy();

	IEnemy(std::string name, Vector2 position) : m_name(name), m_position(position) {}

	virtual IEnemy* clone() = 0;

	std::string GetName() const
	{
		return m_name;
	}

	virtual void SetColour(Colour colour)
	{
		m_colour = colour;
	}

	virtual void SetRadius(float radius)
	{
		m_radius = radius;
	}

	virtual void update(float) = 0;
	virtual void draw() = 0;

protected:
	std::string m_name;
	Vector2 m_position;

	Colour m_colour;
	float m_radius;
};

