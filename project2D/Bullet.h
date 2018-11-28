#pragma once
#include "Vector2D.h"

struct Bullet
{
	Vector2D* position;
	Bullet* next;

	Bullet()
	{
		position = new Vector2D();
		this->position->setX(-75.0f);
		this->position->setY(-75.0f);

		this->next = nullptr;
	}

	~Bullet()
	{
		;
	}


	void moveBullet();

	bool operator == (const Bullet &rhs) const
	{		
		return this->position->yCheck() == rhs.position->yCheck()
			&& this->position->xCheck() == rhs.position->xCheck();
	}

	bool operator != (const Bullet &rhs) const
	{
		return this->position->yCheck() != rhs.position->yCheck()
			|| this->position->xCheck() != rhs.position->xCheck();
	}
};

