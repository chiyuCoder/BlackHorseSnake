#include "stdafx.h"
#include "Food.h"



Food::~Food()
{
}

void Food::setFood()
{	
	while (true) {
		x = rand() % (Wall::ROW - 2) + 1;
		y = rand() % (Wall::COL - 2) + 1;
		if (wall.getBlock(x, y) == wall.EMPTY_CHAR) {
			wall.setBlock(x, y, FOOD_CHAR);
			break;
		}
	}
}
