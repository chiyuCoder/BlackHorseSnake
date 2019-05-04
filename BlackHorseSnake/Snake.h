#pragma once
#include <iostream>
#include "Wall.h"
#include "Food.h"
using namespace std;

class Snake
{
	struct Point {
		int x;
		int y;

		Point* next;
	};
private:
	Point * pHead;

public:
	const char HEAD_CHAR = '@';
	const char BODY_CHAR = '=';
	enum {
		UP = 'w',
		DOWN = 's',
		LEFT = 'a',
		RIGHT = 'd'
	};
	Wall &wall;
	Food &food;
	Snake(Wall& tempWall, Food& tempFood) : wall(tempWall), pHead(NULL), food(tempFood) {};
	~Snake();
	void init();
	void destroyPoint();
	void addPoint(int x, int y);
	void delPoint();
	bool move(const char key);
	Point* getTail();
};

