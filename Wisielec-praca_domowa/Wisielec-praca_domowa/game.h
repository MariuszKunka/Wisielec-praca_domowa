#pragma once
#include <string>
#include <vector>

class Game
{
	enum class GameState
	{
		START,
		UPDATE,
		FINISH
	};



public:
	void OnInit();
	void OnInput();
	bool OnUpdate(float deltatime);
	void OnRender();
	void OnShutdown();
	std::vector<std::string> GetWordsFromFile(std::string filepath);


private:
	std::string guessedWord;
	std::vector<std::string> wordsPool = { "kolor", "silnik", "wzorzec", "silnie", "kanapka" };
	std::vector<bool> guessedLetters;
	GameState gameState = GameState::START;
};