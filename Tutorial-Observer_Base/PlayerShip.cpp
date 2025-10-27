#include "PlayerShip.h"


PlayerShip::PlayerShip() {
	m_active = false;
}

PlayerShip::PlayerShip(std::string shipFileName, std::string bulletFileName) {
	init(shipFileName, bulletFileName);
}

PlayerShip::~PlayerShip() {
	UnloadTexture(*Bullet::BULLET_TEXTURE);
	delete Bullet::BULLET_TEXTURE;
	Bullet::BULLET_TEXTURE = nullptr;

	for (int i = 0; i < MAX_BULLETS; i++) {
		delete m_bullets[i];
	}
}

void PlayerShip::reset(){
    m_pos = Vector2{ 0,0 };
}

void PlayerShip::init(std::string shipFileName, std::string bulletFileName) {

	m_texture = new Texture2D(LoadTexture(shipFileName.c_str()));
	m_tint = RED;
	m_size = { 100,100 };
	m_moveSpeed = 150.0f;
	m_active = true;

	Bullet::BULLET_TEXTURE = new Texture2D(LoadTexture(bulletFileName.c_str()));

	for (int i = 0; i < MAX_BULLETS; i++) {
		m_bullets[i] = nullptr;
	}
}

void PlayerShip::update() {
	if (m_active == true) {
		if (IsKeyDown(KEY_W) == true) {
			m_pos.y += -m_moveSpeed * GetFrameTime();
		}
		if (IsKeyDown(KEY_S) == true) {
			m_pos.y += m_moveSpeed * GetFrameTime();
		}
		if (IsKeyDown(KEY_A) == true) {
			m_pos.x -= m_moveSpeed * GetFrameTime();
		}
		if (IsKeyDown(KEY_D) == true) {
			m_pos.x += m_moveSpeed * GetFrameTime();
		}

		if (m_cooldown > 0) {
			m_cooldown -= GetFrameTime();
		}
		else {
			if (IsKeyDown(KEY_SPACE) == true) {
				m_cooldown = m_fireRate;
				fireBullet();
			}
		}
	}

	for (int i = 0; i < MAX_BULLETS; i++) {
		if (m_bullets[i] != nullptr) {
			m_bullets[i]->update();
		}
	}
}

void PlayerShip::draw(Vector2 screenSize) {
	for (int i = 0; i < MAX_BULLETS; i++) {
		if (m_bullets[i] != nullptr) {
			m_bullets[i]->draw(screenSize);
		}
	}

	GameObject::draw(screenSize);
}

void PlayerShip::destroy() {
}

void PlayerShip::fireBullet() {
	for (int i = 0; i < MAX_BULLETS; i++) {
		if (m_bullets[i] == nullptr) {
			m_bullets[i] = new Bullet(m_pos, Vector2{ 0,-1 });
			break;
		}
		else if (m_bullets[i]->getActive() == false) {
			m_bullets[i]->spawn(m_pos, Vector2{ 0,-1 });
			break;
		}
	}
}
