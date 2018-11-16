#pragma once

class Entity
{
protected:
	//destroy the enemy
	int m_Health;
	int m_Stock;
	// score speeds ships up

	virtual float DoDamage() = 0;
	//score/1000
	//__________
	//   10     
	// added to the speed of all enemies
public:
	// enemy taking damage
	virtual int TakeDamage() = 0;
};