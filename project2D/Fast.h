#pragma once
#include "TestGame.h"


	class Fast
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
			// does 0.5f bc fast boi
		}
		//score/1000
		//__________
		//   10     
		// added to the speed of all enemies
		float ScoreModifier(int score)
		{
			return (score / 1000) / 10;
		}
	public:

		// enemy taking damage
		int TakeDamage(int amount)
		{
			m_Health -= amount;
			this->DestroySelf;
			return m_Health;
		}
	}
};