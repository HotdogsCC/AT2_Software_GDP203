#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include <string>

class PlayerShip : public GameObject {
protected:
	float m_cooldown = 0;
	float m_fireRate = 0.25f;

public:
	const static int MAX_BULLETS = 100;
	Bullet* m_bullets[MAX_BULLETS];

public:
	PlayerShip();
	PlayerShip(std::string shipFileName, std::string bulletFileName);
	~PlayerShip();

	void init(std::string shipFileName, std::string bulletFileName);
	void update() override;
	void draw(Vector2 screenSize) override;
    void reset();
	void destroy();

protected:
	void fireBullet();
};