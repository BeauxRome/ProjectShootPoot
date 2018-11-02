#pragma once



class Enemy
{
protected:
	//destroy the enemy
	void DestroySelf()
	{
		if (m_Health <= 0)
		{
			delete this;
		}
	}
	int m_Health;
	// score speeds ships up
	virtual float MovementSpeed();
	//damage that the enemy ship imparts on whatever it hits
	virtual float DoDamage() = 0;
	//score/1000
	//__________
	//   10     
	// added to the speed of all enemies
	int ScoreModifier;
public:
	// enemy taking damage
	virtual int TakeDamage() = 0;
};
