#include "Pixie.h"



Pixie::Pixie(std::string name) : Bully(name)
{
	this->description = "Bully Pixie";
}

//Each enemy is difficult to beat in two of the three games.  This method calls the appropriate game for this enemy. 
bool Pixie::pickGame() {
	std::string pickedGame;
	Games game = Games();
	std::string answer;

	std::cout << "\nReady to defeat the Pixie? Type 'YES' for yes and 'NO' to quit. " << std::endl;
	std::getline(std::cin, answer);

	while (answer != "NO") {
		std::cout << "\nSelect a game to play to try and defeat the bully. \Enter 'R' for Rock, Paper, Scissors, 'F' for How many fingers am I holding up?, or 'D' for Dice Roll." << std::endl;
		std::getline(std::cin, pickedGame);

		if (pickedGame == "R") {
			riggedRockPaperScissors(&game);
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
		std::cout << "\nYou have defeated the sinister pixie!!  Enraged with anger, she flies away to her den.  From her wings falls the letter 'O'." << std::endl;
		return true;
	}
	else 
		return false;
}
