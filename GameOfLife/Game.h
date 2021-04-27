#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>
#include <thread>
#include "Board.h"

using namespace std::this_thread;
using namespace std::chrono;
#pragma once
class Game
{
private:
	const int WIDTH = 20;
	const int HEIGHT = 20;
	Board* board = new Board(WIDTH, HEIGHT);
public:
	Game();
	void start();
	~Game();
};

