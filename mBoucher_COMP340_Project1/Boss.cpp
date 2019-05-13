#include "Boss.h"



Boss::Boss(std::string name) : Bully(name)
{
	this->description = "Sheriff";
}

Boss::~Boss()
{
}

//This method will run the final game.
void Boss::finalFight() {
	Games game = Games();
	shotgun(&game);

	if (game.playerWins()) {
		std::cout << "\nCONGRATULATIONS!!! You have defeated the Sheriff and are now King of the Slide!" << std::endl;
		int a;
		std::cin >> a;
		exit(0);
	}
}