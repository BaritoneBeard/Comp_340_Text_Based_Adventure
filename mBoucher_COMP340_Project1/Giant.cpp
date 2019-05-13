#include "Giant.h"



Giant::Giant(std::string name) : Bully(name)
{
	this->description = "Bully Giant";
}

//Each enemy is difficult to beat in two of the three games.  This method calls the appropriate game for this enemy. 
bool Giant::pickGame() {
	std::string pickedGame;
	std::string answer;
	Games game = Games();

	std::cout << "\nReady to defeat the Giant? Type 'YES' for yes and 'NO' to quit. " << std::endl;
	std::getline(std::cin, answer);

	while (answer != "NO") {

		std::cout << "\nSelect a game to play to try and defeat the bully. \Enter 'R' for Rock, Paper, Scissors, 'F' for How many fingers am I holding up?, or 'D' for Dice Roll." << std::endl;
		std::getline(std::cin, pickedGame);

		if (pickedGame == "R") {
			rockPaperScissors(&game);
			if (game.playerWins()) {
				break;
			}
			std::cout << "\nYou did not defeat the enemy this time.  Care to try again? Type 'YES' for yes and 'NO' to quit." << std::endl;
			std::getline(std::cin, pickedGame);
		}

		else if (pickedGame == "F") {
			riggedFingers(&game);
			fingers(&game);
			
			if (game.playerWins()) {
				break;
			}
			std::cout << "\nYou did not defeat the enemy this time.  Care to try again? Type 'YES' for yes and 'NO' to quit." << std::endl;
			std::getline(std::cin, pickedGame);
		}

		else if (pickedGame == "D") {
			riggedDice(&game);
			diceGame(&game);
			
			if (game.playerWins()) {
				break;
			}
			std::cout << "\nYou did not defeat the enemy this time.  Care to try again? Type 'YES' for yes and 'NO' to quit." << std::endl;
			std::getline(std::cin, pickedGame);
		}

		else {
			std::cout << "\nHahaha that's not a valid entry! " << std::endl;
			std::getline(std::cin, pickedGame);
		}
	}
	if (game.playerWins()) {
		std::cout << "\nYou have defeated the huge Giant!!  He has gone back to his layer but where his foot stood is now the letter 'R'." << std::endl;
		return true;
	}
	else
		return false;
}

