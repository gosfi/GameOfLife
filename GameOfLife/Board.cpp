#include "Board.h"

Board::Board(int width, int height)
{
	this->width = width;
	this->height = height;
}

std::vector<std::vector<int>> Board::deadState(int width, int height)
{
	std::vector<std::vector<int>> vect(width, std::vector<int>(height, 0));
	return vect;
}

std::vector<std::vector<int>> Board::randomState(int width, int height)
{
	std::vector<std::vector<int>> vec = deadState(width, height);

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			int n = rand() % 5;
			if (n <= 0)
			{
				vec[i][j] = 0;
			}
			else if (n == 4)
			{
				vec[i][j] = 1;
			}
		}
	}

	return vec;
}

int Board::getHeight(vector<vector<int>> vec)
{
	return this->width;
}

int Board::getWidth(vector<vector<int>> vec)
{
	return this->height;
}

void Board::render(std::vector<std::vector<int>> vect)
{

	for (unsigned int i = 0; i < vect.size(); i++)
	{
		for (unsigned int j = 0; j < vect[i].size(); j++)
		{
			if (vect[i][j] == this->DEAD)
			{
				std::cout << "." << " ";
			}
			else
			{
				std::cout << '#' << " ";
			}
		}
		std::cout << std::endl;
	}
}

vector<vector<int>> Board::nextState(vector<vector<int>> vec)
{
	int width = getWidth(vec);
	int height = getHeight(vec);
	vector<vector<int>> nextState = deadState(width, height);

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			coord coord;
			coord.x = i;
			coord.y = j;
			nextState[i][j] = nextCellValue(coord, vec);
		}
	}

	return nextState;
}

int Board::nextCellValue(coord coord, vector<vector<int>> state)
{
	int width = getWidth(state);
	int height = getHeight(state);
	int x = coord.x, y = coord.y;
	int numLiveNeighbors = 0;

	for (int x1 = coord.x - 1; x1 < (coord.x + 1) + 1; x1++)
	{
		if (x1 < 0 || x1 >= width)
		{
			continue;
		}
		for (int y1 = coord.y - 1; y1 < (coord.y + 1) + 1; y1++)
		{
			if (y1 < 0 || y1 >= height)
			{
				continue;
			}
			if (x1 == coord.x && y1 == coord.y)
			{
				continue;
			}
			if (state[x1][y1] == this->LIVE)
			{
				numLiveNeighbors++;
			}
		}
	}

	if (state[x][y] == this->LIVE)
	{
		if (numLiveNeighbors <= 1)
		{
			return this->DEAD;
		}
		else if (numLiveNeighbors <= 3)
		{
			return this->LIVE;
		}
		else if (numLiveNeighbors >= 3)
		{
			return this->DEAD;
		}
		else
		{
			return this->DEAD;
		}
	}
	else
	{
		return this->DEAD;
	}
}

Board::~Board()
{
}
