#pragma once
class Board;

class Game
{
public:
	//returns the amount of neighbours for a tile
	static int CountOnNeighbours(const Board* b, int x, int y);

	//returns the new status for a tile
	static bool NewValue(const Board* b, int x, int y);
};

