#pragma once
#include "Observer.h"
#include <unordered_set>

class Subject
{
public:
	void AddObserver(Observer* observer);
	void RemoveObserver(Observer* observer);

	void Notify(const GameObject* go, Event event);

protected:
	std::unordered_set<Observer*> m_observers;
};

