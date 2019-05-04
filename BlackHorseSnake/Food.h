#pragma once
#include <iostream>
#include "Wall.h"

class Food
{
private:
	Wall& wall;
public:
	const char FOOD_CHAR = '*';
	Food(Wall& tempWall): wall(tempWall) {
	};
	~Food();
	int x;
	int y;
	void setFood();
};

