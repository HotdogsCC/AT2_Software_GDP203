#pragma once

#include "GoblinMelee.h"

class EnemyFactoryWProto
{
public:

	IEnemy* CreateEnemy(std::string type, Vector2 position, std::string prototype)
	{
		if (type == "Goblin Melee" || prototype == "Goblin Melee")
		{
			IEnemy* e = new GoblinMelee(type, position);
			e->clone();
			e->SetColour(SKYBLUE);
			e->SetRadius(25);

			if (type == "Goblin Heavy")
			{
				e->SetColour(RED);
				e->SetRadius(50);
			}

			return e;
		}

		std::cout << "Unknown type: " << type << '\n';

		return nullptr;
	}
};