#include "Bullet.h"

void Bullet::moveBullet()
{

	{
		if (position->xCheck() <= 1280)
		{
			position->setX(position->xCheck()+25.0f);//Juan added
		}
	}
}
