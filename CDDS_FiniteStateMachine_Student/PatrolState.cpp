#include "Vector2D.h"
#include "PatrolState.h"
#include "GameObject.h"

PatrolState::PatrolState() : m_currentWaypoint(0)
{}

PatrolState::~PatrolState()
{}

void PatrolState::onUpdate(GameObject * object, float dt)
{
	Vector2D target = m_waypoints [m_currentWaypoint];
	Vector2D pos = object->getPosition();
	Vector2D dist = { target.x - pos.x, target.y - pos.y };
	float mag = sqrt(dist.x * dist.x + dist.y * dist.y);

	if (mag < 50)
	{
		m_currentWaypoint++;
		if (m_currentWaypoint >= m_waypoints.size())
		{
			m_currentWaypoint = 0;
		}
	}

	Vector2D direction = { dist.x / mag, dist.y / mag };
	float speed = object->getSpeed();
	object->setPosition({ pos.x + (direction.x * speed * dt), pos.y +
		(direction.y * speed * dt) });

	float rot = atan2f(direction.y, direction.x);
	object->setRotation(rot);
}

//As an exercise, implement the ChaseState class on your own. Don’t forget to set 
//	the m_target variable to nullptr in the constructor, and then perform 
//		validation checks on this variable within the onUpdate() function.