#pragma once

class Vector2D
{
protected:
	int yCoor;
	int xCoor;
public:
	void setY(int yVal)
	{
		yCoor = yVal;
	}
	void setX(int xVal)
	{
		xCoor=xVal;
	}

	int yCheck()
	{
		return yCoor;
	}
	int xCheck()
	{
		return xCoor;
	}
	
	int yMove(int shiftNum)
	{
		yCoor = yCoor + shiftNum;
		return yCoor;
	}
	int xMove(int shiftNum)
	{
		xCoor = xCoor + shiftNum;
		return xCoor;
	}
};