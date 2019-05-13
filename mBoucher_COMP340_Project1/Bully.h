#pragma once
#include <string>
#include "Games.h"

//This class is a a top-level enemy class.
class Bully
{
public:
	Bully(std::string name);

	std::string getName();
	std::string getDescription();

	//The following lines are initiating Bully void methods and passing in an instance of Games.
	void rockPaperScissors(Games* game);
	void riggedRockPaperScissors(Games* game);
	void fingers(Games* game);
	void riggedFingers(Games* game);
	void diceGame(Games* game);
	void riggedDice(Games* game);
	void shotgun(Games* game);

	void playerWins(Games game);

	void countOne(Games game);
	void countTwo(Games game);
	bool pickGame();

protected:
	std::string name;
	std::string description;
};

