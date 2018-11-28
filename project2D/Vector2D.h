#pragma once

class Vector2D
{
protected:
	float yCoor;
	float xCoor;
public:
	void setY(float yVal)
	{
		yCoor = yVal;
	}
	void setX(float xVal)
	{
		xCoor=xVal;
	}

	float yCheck()
	{
		return yCoor;
	}
	float xCheck()
	{
		return xCoor;
	}
	
	float yMove(float shiftNum)
	{
		yCoor = yCoor + shiftNum;
		return yCoor;
	}
	float xMove(float shiftNum)
	{
		xCoor = xCoor + shiftNum;
		return xCoor;
	}
};