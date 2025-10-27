#include "Subject.h"

void Subject::AddObserver(Observer* observer)
{
	m_observers.emplace(observer);
}

void Subject::RemoveObserver(Observer* observer)
{
	m_observers.erase(observer);
}

void Subject::Notify(const GameObject* go, Event event)
{
	for (auto observer : m_observers)
	{
		observer->OnNotify(go, event);
	}
}


