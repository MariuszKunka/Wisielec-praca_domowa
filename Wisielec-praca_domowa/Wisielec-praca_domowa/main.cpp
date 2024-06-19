#include <iostream>
#include "Game.h"

using namespace std;

void Initialize();

void GetInput();

bool Update(float deltaTime);

void Render();

void Shutdown();

bool exitGame = false;
Game game;

int main()
{
	

	Initialize();

	while (exitGame)
	{
		GetInput();
		Update(0.0f);
		Render();
		
	}

	Shutdown();


	return 0;
}

void Initialize()
{
	game.OnInit();
}

void GetInput()
{

}

bool Update(float deltaTime)
{
	exitGame = game.OnUpdate(deltaTime);

	return true;
}

void Render()
{
	game.OnRender();
}

void Shutdown()
{
	game.OnShutdown();
}
