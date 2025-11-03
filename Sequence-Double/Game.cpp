#include "Game.h"

#include "Board.h"

int Game::CountOnNeighbours(const Board* b, int x, int y)
{
	int sum = 0;

	//for each tile around us
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			//is this tile us?
			if (i==0 && j==0)
			{
				//iterate
				continue;
			}

			//is there a tile here?
			if (b->At(x + i, y + j))
			{
				//add it to the count
				sum++;
			}
		}
	}

	return sum;
}

bool Game::NewValue(const Board* b, int x, int y)
{
	bool isAlive = b->At(x, y);

	int neighbours = CountOnNeighbours(b, x, y);

	if (isAlive)
	{
		if (neighbours < 2)
		{
			//die
			return false;
		}

		if (neighbours < 4)
		{
			//continue living
			return true;
		}

		//die
		return false;
	}

	//not alive

	if (neighbours == 3)
	{
		//become alive
		return true;
	}

	//stay dead
	return false;
}
