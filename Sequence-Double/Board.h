#pragma once
#include <raylib.h>

class Board
{
public:
	Board(int x, int y, Color tint = YELLOW);

	~Board();


	//returns the tile at a given coordinate
	bool& At(int x, int y) const;

	//draw the board given the amount of pixels per tile
	void Draw(int px) const;

private:
	//the tile states
	bool* board = nullptr;

	//the size of the board in tiles horizontally
	int xdim;

	//the size of the board in tiles vertically
	int ydim;

	//the colour of each tile
	Color tint;
};

