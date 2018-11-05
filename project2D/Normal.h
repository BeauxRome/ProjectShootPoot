#pragma once

class Normal
{
private:
	int m_Health = 1;
	//destroy the enemy
	void DestroySelf()
	{
		if (m_Health <= 0)
		{
			delete this;
		}
	}
	// score speeds ships up
	float MovementSpeed()
	{

	}
	//damage that the enemy ship imparts on whatever it hits
	float DoDamage()
	{
		//does 1 bc normal
	}
	//score/1000
	//__________
	//   10     
	// added to the speed of all enemies
	int ScoreModifier;
public:
	// enemy taking damage
	int TakeDamage()
	{
		m_Health--;
		this->DestroySelf;
	}
};
