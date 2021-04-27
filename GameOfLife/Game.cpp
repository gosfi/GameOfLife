#include "Game.h"

Game::Game()
{
}

void Game::start()
{
	srand(time(NULL));
	char x;
	std::vector<std::vector<int>> vec;
	//vec = this->board->loadBoardState("../Toad.txt");
	vec = this->board->randomState(this->WIDTH, this->HEIGHT);
	while(true)
	{
		vec = this->board->nextState(vec);
		this->board->render(vec);
		sleep_until(system_clock::now() + milliseconds(500));
		system("cls");
	}
}

Game::~Game()
{
}
