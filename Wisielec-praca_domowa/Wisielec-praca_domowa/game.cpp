#include "game.h"
#include <cstdlib>
#include <ctime>

void Game::OnInit()
{
	guessedLetters.clear();
	srand(std::time(NULL));

	int randomIndex = rand() % wordsPool.size();

	testWord = wordsPool[randomIndex];
}

void Game::OnInput()
{

}

bool Game::OnUpdate(float deltatime)
{

	return false;
}

void Game::OnRender()
{

}

void Game::OnShutdown()
{
	guessedLetters.clear();

}
