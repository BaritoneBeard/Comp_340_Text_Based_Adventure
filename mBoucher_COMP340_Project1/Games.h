#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
class Games
{
public:
	Games();

	//The following several lines are initiating void methods.  Games are used as my combat action throughout the program. 
	void rockPaperScissors();
	void riggedRockPaperScissors();
	void fingers();
	void riggedFingers();
	bool diceGame();
	void riggedDice();
	bool playerWins();
	void diceRoll();
	void shotgun();

	void riggedCounterOne();
	void riggedCounterTwo();
	void riggedCounterThree();

	int getCountOne();
	int getCountTwo();
	int getCountThree();

	//Revisions for the Final Project
	//void sticksGameAI(int i); //rig the game by making the AI smarter
	void sticksGame(bool rigged);
	int sticksToOne(int i);
	int playerTurnSticks(int i);
	void tictactoe(bool rigged);
	int checkBoard(char board[], char xo, char check);
	int lineCheck(char a, char b, char c, char xo, char check);
	int decision(char board[], char xo, char check);

private:
	std::vector<std::string > enemyRockChoice;
	std::vector<std::string > enemyShotgunChoice;
	std::vector<int> diceChoice;
	bool win;
	int counterOne = 0;
	int counterTwo = 0;
	int counterThree = 0;
};

