#include "Goblin.h"



Goblin::Goblin(std::string name) : Classmate(name)
{
	this->description = "Bully Cowboy";
}

//Each classmate has an individual task to accomplish.  This method calls the appropriate task for this enemy. 
bool Goblin::enterPassword() {
	std::string password;
	std::string option = "0";
	std::cout << "'To obtain access to the slide, enter the password!'" << std::endl;
	std::getline(std::cin, password);

	while (password != "INCORRECT") {
		std::cout << "\nThe password is incorrect. \nNeed a hint?  Type 1, 2 or 3 for hints or 0 to continue." << std::endl;
		std::cin >> option;
		std::cin.ignore();

		if (option == "1") {
			std::cout << "\nGood golly Miss Molly! You can use the letters more than once! \n" << std::endl;
			std::cout << "\nTo obtain access to the slide, enter the password!" << std::endl;
			std::getline(std::cin, password);
		}
		else if (option == "2") {
			std::cout << "\nGeez Louise Papa Cheese!  'I' will begin, to help you. \n" << std::endl;
			std::cout << "\nTo obtain access to the slide, enter the password!" << std::endl;
			std::getline(std::cin, password);
		}
		else if (option == "3") {
			std::cout << "\nGet out of town Funky Brown! I already told you the password! \n" << std::endl;
			std::cout << "\nTo obtain access to the slide, enter the password!" << std::endl;
			std::getline(std::cin, password);
		}
		else {
			option = "0";
		}
		if (option == "0")
			break;
	}
	if (password == "INCORRECT") {
		this->havePassword = true;
	}
	if (havePassword) {

		std::cout << "\nYou got it dude!" << std::endl;
		return havePassword;
	}
	else {
		std::cout << "\nYou haven't found it yet!  Nice try!" << std::endl;
		return false;
	}
}