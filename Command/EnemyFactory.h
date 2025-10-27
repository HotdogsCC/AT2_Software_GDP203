#pragma once

#include "MeleeEnemy.h"
#include "HeavyEnemy.h"

class EnemyFactory
{
public:
	Enemy* CreateEnemy(std::string type, Vector2 position);
};

