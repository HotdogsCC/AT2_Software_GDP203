#pragma once
#include "GameObject.h"

class Asteroid : public GameObject {
public:
	static Texture2D* ASTEROID_TEXTURE;
	static const int MAX_ASTEROIDS = 100;

public:
	Asteroid();
	Asteroid(Vector2 spawnPos, Vector2 direction);
	~Asteroid();

	void init(Vector2 spawnPos, Vector2 direction);
	void update() override;
	void draw(Vector2 screenSize) override;

	void spawn(Vector2 spawnPos, Vector2 direction);
	void destroy();
};