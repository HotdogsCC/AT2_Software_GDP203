#include "GameObject.h"

GameObject::GameObject(TransformComponent* transform, MoveableComponent* moveable, SpriteComponent* sprite) :
	m_transform(transform), m_moveable(moveable), m_sprite(sprite) {}

GameObject::~GameObject()
{
	delete m_transform;
	delete m_moveable;
	delete m_sprite;
}


void GameObject::Update()
{
	Vector2 pos = m_transform->GetPosition();
	m_moveable->Update(pos);
	m_transform->SetPosition(m_moveable->GetPosition());
}

void GameObject::Draw()
{
	m_sprite->Draw(m_transform->GetPosition());
}
