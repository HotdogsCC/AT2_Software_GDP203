#pragma once
#include "Observer.h"

class AchievementSystem : public Observer
{
public:
	void OnNotify(const GameObject* object, Event event) override;

protected:
	int m_asteroidsDestroyed = 0;
	int m_asteroidsSpawned = 0;
	int m_playerDeaths = 0;
	int m_bulletsShot = 0;
};

inline AchievementSystem ACHIEVEMENT_SYSTEM = AchievementSystem();