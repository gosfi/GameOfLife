#include "Game.h"

Game::Game()
{
}

void Game::start()
{
	srand(time(NULL));

	std::vector<std::vector<int>> vec;

	vec = this->board->randomState(this->WIDTH, this->HEIGHT);
	while(true)
	{
		
		vec = this->board->nextState(vec);
		this->board->render(vec);
	}
}

Game::~Game()
{
}
