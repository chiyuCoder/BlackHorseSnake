#include "stdafx.h"
#include "Wall.h"


Wall::Wall()
{
}


Wall::~Wall()
{
}

void Wall::init() {
	for (int i = 0; i < ROW; i ++) {
		for (int j = 0; j < COL; j ++) {
			if (i % (ROW - 1) == 0 || j % (COL - 1) == 0) {
				gameArray[i][j] = BLOCK_CHAR;
			}
			else {
				gameArray[i][j] = EMPTY_CHAR;
			}
		}
	}
}

void Wall::drawWall()
{
	system("cls");
	for (int i = 0; i < ROW; i ++) {
		for (int j = 0; j < COL; j ++) {
			cout << gameArray[i][j] << " ";
		}
		if (i == 4) {
			cout << "  created by BlackHorse Course";
		}
		if (i == 6) {
			cout << "  key \"a\" -- to left";
		}
		if (i == 8) {
			cout << "  key \"s\" -- to bottom";
		}
		if (i == 10) {
			cout << "  key \"w\" -- to top";
		}
		if (i == 12) {
			cout << "  key \"d\" -- to right";
		}

		cout << endl;
	}
}

void Wall::setBlock(int x, int y, char ch)
{
	gameArray[x][y] = ch;
}

char Wall::getBlock(int x, int y)
{
	return gameArray[x][y];
}
