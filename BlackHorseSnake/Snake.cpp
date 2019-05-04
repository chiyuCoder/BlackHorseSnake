#include "stdafx.h"
#include "Snake.h"




Snake::~Snake()
{
}

void Snake::init()
{
	destroyPoint();
	addPoint(5, 3);
	addPoint(5, 4);
	addPoint(5, 5);
}

void Snake::destroyPoint()
{
	Point* head = pHead;
	Point* cur = NULL;
	while (head) {
		cur = head->next;
		delete head;
		head = cur;
	}
}

void Snake::addPoint(int x, int y)
{
	Point* newPoint = new Point();
	newPoint->x = x;
	newPoint->y = y;
	newPoint->next = NULL;
	if (pHead != NULL) {
		wall.setBlock(pHead->x, pHead->y, BODY_CHAR);
	}
	newPoint->next = pHead;
	wall.setBlock(newPoint->x, newPoint->y, HEAD_CHAR);
	pHead = newPoint;
}

void Snake::delPoint()
{
	if (pHead == NULL || pHead->next == NULL) {
		return;
	}
	Point* pre = pHead;
	Point* cur = pHead->next;
	while (cur->next != NULL) {
		pre = pre->next;
		cur = cur->next;
	}
	wall.setBlock(cur->x, cur->y, wall.EMPTY_CHAR);
	delete cur;
	cur = NULL;
	pre->next = NULL;
}

bool Snake::move(const char key)
{
	int headX = pHead->x;
	int headY = pHead->y;

	switch (key) {
	case UP:
		headX--;
		break;
	case DOWN:
		headX++;
		break;
	case LEFT:
		headY--;
		break;
	case RIGHT:
		headY++;
		break;
	}
	const char ch = wall.getBlock(headX, headY);
	if (
		ch == wall.BLOCK_CHAR
		|| ch == BODY_CHAR
	) {
		cout << "GAME OVER" << endl;
		return false;
	}
	if (ch == food.FOOD_CHAR) {// '*' should be replaced by Food.FOOD_CHAR
		addPoint(headX, headY);
		food.setFood();
	}
	else {
		addPoint(headX, headY);
		delPoint();
	}
	return true;
}

Snake::Point * Snake::getTail()
{
	if (pHead == NULL || pHead->next == NULL) {
		return nullptr;
	}
	Point* pre = pHead;
	Point* cur = pHead->next;
	while (cur->next != NULL) {
		pre = pre->next;
		cur = cur->next;
	}
	return cur;
}
