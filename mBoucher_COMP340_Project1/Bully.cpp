#include "Bully.h"

Bully::Bully(std::string name)
{
	this->name = name;
}

std::string Bully::getName() {
	return this->name;
}

std::string Bully::getDescription() {
	return this->description;
}
//The following several methods are creating different instances of game. 
void Bully::rockPaperScissors(Games* game) {
	game->rockPaperScissors();
}
void Bully::riggedRockPaperScissors(Games* game) {
	game->riggedRockPaperScissors();
}
void Bully::fingers(Games* game) {
	game->fingers();
}
void Bully::riggedFingers(Games* game) {
	game->riggedFingers();
}
void Bully::diceGame(Games* game) {
	game->diceGame();
}
void Bully::riggedDice(Games* game) {
	game->riggedDice();
}
void Bully::shotgun(Games* game) {
	game->shotgun();
}
void Bully::playerWins(Games game) {
	game.playerWins();
}
void Bully::countOne(Games game) {
	game.riggedCounterOne();
}
void Bully::countTwo(Games game) {
	game.riggedCounterTwo();
}