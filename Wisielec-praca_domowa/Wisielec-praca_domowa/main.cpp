#include <iostream>
#include "Game.h"

using namespace std;

void Initialize();

void GetInput();

void Update();

void Render();

void Shutdown();

bool exitGame = false;

int main()
{
	Game game;

	Initialize();

	while (exitGame)
	{
		GetInput();
		Update();
		Render();
		
	}

	Shutdown();


	return 0;
}

void Initialize()
{
}

void GetInput()
{
}

void Update()
{
}

void Render()
{
}

void Shutdown()
{
}
