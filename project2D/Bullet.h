#pragma once
#include "Vector2D.h"
#include "Standard.h"

struct Bullet
{
	Vector2D* position;

	Bullet()
	{
		position = new Vector2D();
		this->position->setX(-75.0f);
		this->position->setY(-75.0f); 
	}

	~Bullet()
	{
		
	}


	void moveBullet();

	bool operator == (const Bullet &rhs) const
	{		
		if (&rhs == nullptr)
			return false;
		return this->position->yCheck() == rhs.position->yCheck()
			&& this->position->xCheck() == rhs.position->xCheck();
	}

	bool operator != (const Bullet &rhs) const
	{		
		if (&rhs == nullptr)
			return false;
		return this->position->yCheck() != rhs.position->yCheck()
			|| this->position->xCheck() != rhs.position->xCheck();
	}
};

