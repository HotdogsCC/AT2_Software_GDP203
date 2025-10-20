#include "EnemyFactory.h"

Enemy* EnemyFactory::CreateEnemy(std::string type, Vector2 position)
{
	if (type == "Melee")
	{
		return new MeleeEnemy(type, position);
	}

	if (type == "Heavy")
	{
		return new HeavyEnemy(type, position);
	}

	std::cout << "Unknown type : " << type << '\n';

	return nullptr;
}
