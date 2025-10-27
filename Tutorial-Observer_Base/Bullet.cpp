#include "Bullet.h"

#include <raymath.h>

Texture2D* Bullet::BULLET_TEXTURE = nullptr;

Bullet::Bullet() {
	m_active = false;
}

Bullet::Bullet(Vector2 spawnPos, Vector2 direction) {
	init(spawnPos, direction);
}

Bullet::~Bullet() {
	m_texture = nullptr;
}

void Bullet::init(Vector2 spawnPos, Vector2 direction) {

	m_texture = BULLET_TEXTURE;
	m_tint = DARKPURPLE;
	m_size = { 50,50 };
	m_moveSpeed = 200;

	spawn(spawnPos, direction);
}

void Bullet::update() {
	if (m_active == true) {
		m_pos = Vector2Add(m_pos, Vector2Scale(m_velocity, GetFrameTime()));
	}
}

void Bullet::draw(Vector2 screenSize) {
	GameObject::draw(screenSize);
}

void Bullet::spawn(Vector2 spawnPos, Vector2 direction) {
	m_active = true;

	m_pos = spawnPos;
	m_velocity = Vector2Scale(direction, m_moveSpeed);
}

