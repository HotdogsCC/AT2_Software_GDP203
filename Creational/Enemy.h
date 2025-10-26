#pragma once

#include <string>
#include "raylib.h"

class Enemy
{
public:
	Enemy()
	{

	};

	Enemy(std::string name, Vector2 position) : m_name(name), m_position(position)
	{
	}

	virtual void update(float) = 0;
	virtual void draw() = 0;

protected:
	std::string m_name;
	Vector2 m_position;
};