#include<iostream>
#include "game.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <windows.h>

using namespace std;

void Game::OnInit()
{
	guessedLetters.clear();
	srand(std::time(NULL));

	wordsPool = GetWordsFromFile("E:\\Github\\Wisielec\\Wisielec-praca_domowa\\Wisielec-praca_domowa\\x64\\Debug\\words.txt");
	int randomIndex = rand() % wordsPool.size();

	guessedWord = wordsPool[randomIndex];

	for (int i = 0; i < guessedWord.length(); ++i)
	{
		guessedLetters.push_back(false);
	}

	OnRender();
}

void Game::OnInput()
{
	char letter;
	cin >> letter;
	cout << letter;

	if (!CheckInputLetter(letter))
	{
		lifeCounter--;
	}
}


bool Game::OnUpdate(float deltatime)
{
	Sleep(deltatime);
	system("cls");
	if (!isFinished)
	{
		if (lifeCounter <= 0)
		{
			isFinished = true;
		}
		bool isAllLettersFound = true;
		for (int i = 0; i < guessedWord.length(); ++i)
		{
			if (!guessedLetters[i])
			{
				isAllLettersFound = false;
				break;
			}
		}
		if (isAllLettersFound)
		{
			isWon = true;
			isFinished = true;
		}
	}

	return isFinished;
}

void Game::OnRender()
{
	cout << guessedWord << endl; // debugowe
	string displayedWord = guessedWord;
	for (int i = 0; i < guessedWord.length(); ++i)
	{
		if (guessedLetters[i])
		{
			displayedWord[i] = guessedWord[i];
		}
		else
		{
			displayedWord[i] = '_';
		}
	}

	cout << "Pozostale szanse: " << lifeCounter <<endl;
	cout << "Slowo: " << "(" << displayedWord.length() << ")" << displayedWord << endl;

	if (isFinished)
	{
		if (isWon)
		{
			cout << "Zwyciestwo!!!" << endl;
		}
		else
		{
			cout << "Porazka!!! " << endl;
		}
	}
	else
	{
		cout << "Podaj litere: ";
	}
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

bool Game::CheckInputLetter(char letter)
{
	bool result = false;
	for (int i = 0; i < guessedWord.length(); ++i)
	{
		if (guessedWord[i] == letter)
		{
			if (guessedLetters[i])
			{
				return false;
			}
			else
			{
				guessedLetters[i] = true;
				result = true;
			}
		}
	}
	return result;
}
