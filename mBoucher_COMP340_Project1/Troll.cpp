#include "Troll.h"

Troll::Troll(std::string name) : Classmate(name)
{
	this->description = "Classmate Troll";
}

//Each classmate has an individual task to accomplish.  This method calls the appropriate task for this enemy. 
bool Troll::solveTheRiddle(std::vector<std::string > inventory) {
	std::cout << "'To cross my bridge you must find for me \nTwo items around the park you'll see \nTwo words as one, they become the key \nBored until you return I'll be'" << std::endl;

	std::cout << "\n'I have keys, but no locks and space, and no rooms. You can enter, but you can’t go outside. What am I?'" << std::endl;
	haveKey = false;
	haveBoard = false;
	for (std::string e : inventory) {
		if (e == "KEY") {
			this->haveKey = true;
		}
		if (e == "BOARD") {
			this->haveBoard = true;
		}
	}
	if (haveBoard && haveKey) {
		std::cout << "\n'Hooray for you hooray for me! \nYou found the board, you found the key! \nThe answer 'keyboard' you did see \nSolves the puzzle and here's your 'c' '" << std::endl;
		std::cout << "\nThe Troll hands you the letter 'C.'" << std::endl;
		return true;
	}
	else if (haveBoard) {
		std::cout << "\n'Not just yet are you free. \nI said TWO items you will see.'" << std::endl;
		return false;
	}
	else if (haveKey) {
		std::cout << "\n'Not just yet are you free. \nI said TWO items you will see.'" << std::endl;
		return false;
	}
	else {
		std::cout << "\n'Not just yet are you free. \nLook at my riddle again and see. \nThe items that make up the key. \nGo find them and bring them to me.'" << std::endl;
		return false;
	}
}