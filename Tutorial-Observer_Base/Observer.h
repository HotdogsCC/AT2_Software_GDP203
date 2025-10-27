#pragma once

class GameObject;

enum class Event
{
	DAMAGED,
	SPAWNED
};

class Observer
{
public:
	virtual void OnNotify(const GameObject* object, Event event) = 0;
};
