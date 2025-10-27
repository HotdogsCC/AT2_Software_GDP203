#include "AchievementSystem.h"
#include <iostream>
#include "Asteroid.h"
#include "PlayerShip.h"

void AchievementSystem::OnNotify(const GameObject* object, Event event)
{
	//do a different thing based on the type of event
	switch (event)
	{
	case Event::DAMAGED:
		//is it an asteroid?
		if (dynamic_cast<const Asteroid*>(object))
		{
			//increment asteroids destroyed
			m_asteroidsDestroyed++;

			//achievement messages
			if (m_asteroidsDestroyed == 10)
			{
				std::cout << "10 ASTEROIDS DESTROYED!!\n";
			}
			else if (m_asteroidsDestroyed == 100)
			{
				std::cout << "100 ASTEROIDS DESTROYED!!\n";
			}
		}

		//is it a player?
		else if (dynamic_cast<const PlayerShip*>(object))
		{
			m_playerDeaths++;

			if (m_playerDeaths == 1 && m_asteroidsDestroyed == 0)
			{
				std::cout << "Fun fact! The SPACEBAR can be used to fire projectiles!\n";
			}
		}

		break;
	case Event::SPAWNED:
		//is it an asteroid?
		if (dynamic_cast<const Asteroid*>(object))
		{
			m_asteroidsSpawned++;

			if (m_asteroidsSpawned == 100 && m_asteroidsDestroyed >= 90)
			{
				std::cout << "Good aim!\n";
			}
			else if (m_asteroidsSpawned == 100 && m_asteroidsDestroyed <= 50)
			{
				std::cout << "Bad aim!\n";
			}
		}

		break;
	default:
		break;
	}
}
