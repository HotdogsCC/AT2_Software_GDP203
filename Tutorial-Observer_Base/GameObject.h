#pragma once

#include <raylib.h>
#include <string>

class GameObject {
protected:
	Vector2 m_pos{ 0,0 };
	float m_rot = 0;
	float m_scale = 1;
	Vector2 m_size{ 50,50 };
	Vector2 m_velocity{ 0,0 };
	float m_moveSpeed = 150;

	Texture2D* m_texture = nullptr;
	Color m_tint = WHITE;
	bool m_active = false;

public:
	GameObject();
	GameObject(std::string fileName);
	~GameObject();

	virtual void init(std::string fileName);
	virtual void update();
	virtual void draw(Vector2 screenSize);

	bool checkCollision(const GameObject* other) const;

	// Getters and Setters
	float getRadius() const;

	bool getActive() const;
	void setActive(bool newActive);

	Vector2 getPos() const;

	Vector2 getVelocity() const;
	void addVelocity(Vector2 newVelocity);
};