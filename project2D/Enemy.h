#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Enemy
{

public:
	Vector2D * enemyCoor=new Vector2D;

	void setCoor()
	{
		srand(time(NULL));
		enemyCoor->setX(1280.0f);//Juan added
		enemyCoor->setY(rand() % 225 + 75 + rand() % 225 + 75);//Juan added
	}

	Enemy()
	{
		srand(time(NULL));
		enemyCoor->setX(1280.0f);//Juan added
		enemyCoor->setY(rand() % 550 + 150);//Juan added;
	}

	~Enemy()
	{
		;
	}

	void movementSpd()
	{
		enemyCoor->setX(enemyCoor->xCheck() + 50);
	}
};