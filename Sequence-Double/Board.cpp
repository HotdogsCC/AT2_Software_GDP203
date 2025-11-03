#include "Board.h"

Board::Board(int x, int y, Color tint):
	board{ new bool[x * y] },
	xdim(x),
	ydim(y),
	tint(tint)
{
	for (int i = 0; i < xdim * ydim; i++)
	{
		board[i] = false;
	}
}


Board::~Board()
{
	delete[] board;
}

bool& Board::At(int x, int y) const
{
	while (x < 0)
	{
		x += xdim;
	}

	while (y < 0)
	{
		y += ydim;
	}

	x %= xdim;
	y %= ydim;

	return board[x + y * xdim];
}


void Board::Draw(int px) const
{
	//draw the area for all the tiles
	DrawRectangle(0, 0, xdim * px, ydim * px, BLACK);

	//draw each tile in the grind
	for (int x = 0; x < xdim; x++)
	{
		for (int y = 0; y < ydim; y++)
		{
			if (At(x,y))
			{
				DrawRectangle(x * px + 1, y * px + 1, px - 2, px - 2, tint);
			}
		}
	}
}
