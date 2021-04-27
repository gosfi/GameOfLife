#include <iostream>
#include <time.h>
#include <vector>
#include <string>
#include <fstream>
using std::vector;
#pragma once

class Board
{
private:
	struct coord
	{
		int x;
		int y;
	};
	int height,width;
	const int DEAD = 0;
	const int LIVE = 1;
public:
	Board(int width, int height);
	vector<vector<int>> deadState(int width, int height);
	vector<vector<int>> randomState(int width, int height);
	int getHeight(vector<vector<int>> vec);
	int getWidth(vector<vector<int>> vec);
	void render(vector<vector<int>> vect);
	vector<vector<int>> nextState(vector<vector<int>> vec);
	int nextCellValue(coord coord, vector<vector<int>> state);
	vector<vector<int>> loadBoardState(std::string path);
	~Board();
};

