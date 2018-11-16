#pragma once
#include "Vector2D.h"

struct Bullet : public Vector2D
{
	Vector2D position;
	Vector2D* next;
};
