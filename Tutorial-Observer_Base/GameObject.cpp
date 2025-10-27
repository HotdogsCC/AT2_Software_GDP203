#include "GameObject.h"
#include <raymath.h>

GameObject::GameObject() {
	m_active = false;
}

GameObject::GameObject(std::string fileName) {
	init(fileName);
}

GameObject::~GameObject() {
	if (m_texture != nullptr) {
		UnloadTexture(*m_texture);
		delete m_texture;
		m_texture = nullptr;
	}
}

void GameObject::init(std::string fileName) {
	m_texture = new Texture2D(LoadTexture(fileName.c_str()));
	m_active = true;
}

void GameObject::update() {
}

void GameObject::draw(Vector2 screenSize) {
	if (m_active == true) {
		if (m_texture != nullptr) {
			DrawTexturePro(
				// Source texture
				*m_texture,
				// What part of the source texture is used (useful when using spritesheets)
				Rectangle{ 0,0,(float)m_texture->width, (float)m_texture->height },
				// The position and size of the sprite
				Rectangle{ screenSize.x * 0.5f + m_pos.x, screenSize.y * 0.5f + m_pos.y,
							m_size.x * m_scale, m_size.y * m_scale },
				// The origin point used for the sprite
				Vector2{ m_size.x * 0.5f * m_scale, m_size.y * 0.5f * m_scale },
				m_rot,
				m_tint
			);
		}
		else {
			DrawCircle(m_pos.x, m_pos.y, (m_size.x + m_size.y) * 0.5f, m_tint);
		}
	}
}

bool GameObject::checkCollision(const GameObject* other) const {
	Vector2 diff = Vector2Subtract(m_pos, other->m_pos);
	float dist = powf(diff.x, 2) + powf(diff.y, 2); // Squared distance
	float colRadius = powf(getRadius() + other->getRadius(), 2);

	return dist <= colRadius;
}

float GameObject::getRadius() const {
	//		Average of length and width * scale   * halved for radius
	return (m_size.x + m_size.y) * 0.5f * m_scale * 0.5f;
}

bool GameObject::getActive() const {
	return m_active;
}

void GameObject::setActive(bool newActive) {
	m_active = newActive;
}

Vector2 GameObject::getPos() const {
	return m_pos;
}

Vector2 GameObject::getVelocity() const {
	return m_velocity;
}

void GameObject::addVelocity(Vector2 newVelocity) {
	m_velocity = Vector2Add(m_velocity, newVelocity);
}
