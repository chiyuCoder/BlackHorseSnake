#pragma once
#include <iostream>
#include <string>

using namespace std;

class Wall
{

public:
	Wall();
	~Wall();
	enum
	{
		ROW = 26,
		COL = 26
	};
	const char BLOCK_CHAR = '#';
	const char EMPTY_CHAR = ' ';
	void init();
	void drawWall();
	void setBlock(int x, int y, char ch);
	char getBlock(int x, int y);
private:
	char gameArray[ROW][COL];
};

