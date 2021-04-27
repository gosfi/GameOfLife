#include <iostream>
#include <vector>
#include <time.h>
#include "Board.h"
#pragma once
class Game
{
private:
	const int WIDTH = 30;
	const int HEIGHT = 30;
	Board* board = new Board(WIDTH, HEIGHT);
public:
	Game();
	void start();
	~Game();
};

