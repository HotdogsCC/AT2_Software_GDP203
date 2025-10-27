#pragma once
#include "GameObject.h"

class Bullet : public GameObject {
public:
	static Texture2D* BULLET_TEXTURE;

public:
	Bullet();
	Bullet(Vector2 spawnPos, Vector2 direction);
	~Bullet();

	void init(Vector2 spawnPos, Vector2 direction);
	void update() override;
	void draw(Vector2 screenSize) override;

	void spawn(Vector2 spawnPos, Vector2 direction);
};