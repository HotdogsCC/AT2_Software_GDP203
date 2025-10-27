#include "Asteroid.h"
#include <raymath.h>
#include "AchievementSystem.h"

Texture2D* Asteroid::ASTEROID_TEXTURE = nullptr;

Asteroid::Asteroid() {
}

Asteroid::Asteroid(Vector2 spawnPos, Vector2 direction) {
	init(spawnPos, direction);
}

Asteroid::~Asteroid() {
	m_texture = nullptr;
}

void Asteroid::init(Vector2 spawnPos, Vector2 direction) {
	m_texture = ASTEROID_TEXTURE;
	m_tint = GRAY;
	m_size = { 50,50 };

	AddObserver(&ACHIEVEMENT_SYSTEM);

	spawn(spawnPos, direction);
}

void Asteroid::update() {
	if (m_active == true) {
		m_pos = Vector2Add(m_pos, Vector2Scale(m_velocity, GetFrameTime()));
	}
}

void Asteroid::draw(Vector2 screenSize) {
	GameObject::draw(screenSize);
}

void Asteroid::spawn(Vector2 spawnPos, Vector2 direction) {
	m_pos = spawnPos;
	m_rot = rand() % 360; // 0-365
	m_scale = 2 + (rand() % 15 - 10) * 0.1f; // 1-2.5
	m_velocity = Vector2Scale(direction, rand() % 20 + 20); // 20-40
	m_active = true;
	Notify(this, Event::SPAWNED);
}

void Asteroid::destroy() {
	m_active = false;
	Notify(this, Event::DAMAGED);
}