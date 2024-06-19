#include<iostream>
#include "game.h"
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

void Game::OnInit()
{
	guessedLetters.clear();
	srand(std::time(NULL));

	wordsPool = GetWordsFromFile("E:\\Github\\Wisielec\\Wisielec-praca_domowa\\Wisielec-praca_domowa\\x64\\Debug\\words.txt");
	int randomIndex = rand() % wordsPool.size();

	guessedWord = wordsPool[randomIndex];

	cout << guessedWord << endl;
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

vector<string> Game::GetWordsFromFile(string filepath)
{
	vector<string> result = vector<string>();
	fstream file;
	char guessedWord[15];

	file.open(filepath, ios::in);
	if (file.is_open())
	{
		while (!file.eof())
		{
			while (file.getline(guessedWord, 100))
			{
				string abc(guessedWord);
				result.push_back(abc);
			}
		}
	}

	return result;
}
