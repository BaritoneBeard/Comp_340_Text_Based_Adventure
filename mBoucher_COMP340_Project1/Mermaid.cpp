#include "Mermaid.h"



Mermaid::Mermaid(std::string name) : Classmate(name)
{

	this->description = "Classmate Mermaid";
}
//Each classmate has an individual task to accomplish.  This method calls the appropriate task for this enemy. 
bool Mermaid::iSpy(std::vector<std::string > inventory) {
	int hint;
	int option = 0;

	std::cout << "\n'I spy with my little eye something that can spy me.' \nNeed a hint? Type 1, 2 or 3 for hints or 0 to continue." << std::endl;
	std::cin >> hint;
	std::cin.ignore();

	while (hint != 0) {

		if (hint == 1) {
			std::cout << "\n'Objects may a-peer bigger than what they seem.'\n" << std::endl;
			std::cout << "\n'I spy with my little eye something that can spy me.' \nNeed a hint? Type 1, 2 or 3 for hints or 0 to continue." << std::endl;
			std::cin >> hint;
			std::cin.ignore();
		}
		else if (hint == 2) {
			std::cout << "\n'Ayeee may be seen with pirates at sea.'\n" << std::endl;
			std::cout << "\n'I spy with my little eye something that can spy me.' \nNeed a hint? Type 1, 2 or 3 for hints or 0 to continue." << std::endl;
			std::cin >> hint;
			std::cin.ignore();
		}
		else if (hint == 3) {
			std::cout << "\n'My parts lens itself to be very useful.' \n" << std::endl;
			std::cout << "\n'I spy with my little eye something that can spy me.' \nNeed a hint? Type 1, 2 or 3 for hints or 0 to continue." << std::endl;
			std::cin >> hint;
			std::cin.ignore();
		}
		else {
			std::cout << "\n'I spy with my little eye something that can spy me.' \nNeed a hint? Type 1, 2 or 3 for hints or 0 to continue." << std::endl;
			std::cin >> hint;
			std::cin.ignore();
		}
	}
	std::cout << "\n'Did you find what I spy?  Let's see!'" << std::endl;
	this->haveSpy = false;
	for (std::string e : inventory) {
		if (e == "SPYGLASS") {
			this->haveSpy = true;
		}
	}
	if (haveSpy) {
		std::cout << "\n'Ah you spied what I spied!  Here's an 'I' for an eye!'" << std::endl;
		return haveSpy;
	}
	else {
		std::cout << "\n'You haven't found it yet!  Nice try!'" << std::endl;
		return false;
	}
}
