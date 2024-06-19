#pragma once
#include <string>
#include <vector>

class Game
{
public:
	void OnInit();
	void OnInput();
	bool OnUpdate(float deltatime);
	void OnRender();
	void OnShutdown();
	std::vector<std::string> GetWordsFromFile(std::string filepath);


private:
	bool CheckInputLetter(char letter);
	std::string guessedWord;
	std::vector<std::string> wordsPool = { "kolor", "silnik", "wzorzec", "silnie", "kanapka" };
	std::vector<bool> guessedLetters;
	int lifeCounter = 10;
	bool isFinished = false;
	bool isWon = false;


};