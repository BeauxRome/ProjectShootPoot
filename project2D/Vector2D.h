#pragma once

class Vector2D
{
protected:
	float yCoor;
	float xCoor;
public:

	//Gives the x and y coordinates difinition
	void setY(float yVal)
	{
		yCoor = yVal;
	}
	void setX(float xVal)
	{
		xCoor=xVal;
	}


	//Checks the x and y coordinates, since they are protected
	float yCheck()
	{
		return yCoor;
	}
	float xCheck()
	{
		return xCoor;
	}sssss
	
};