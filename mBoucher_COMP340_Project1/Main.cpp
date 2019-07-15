#include <iostream>
#include <vector>
#include "Room.h"
#include "Player.h"
#include "Monkey.h"
#include "Centaur.h"
#include "Goblin.h"
#include "Games.h"



int main() {

	std::string userInput;
	Room* currentRoom = nullptr;
	Player player = player;
	std::vector<Room*> rooms;

	std::cout << "'Hi! My name is Jimmy! Thanks for going to the park with me.  It's my favorite place to go exploring.  You never know what kind of creatures we'll meet or adventures we'll have!  Let's go!!!' \n\nType 'HELP' at any time for a list of commands." << std::endl;

	//The following several lines create a room and set up the descriptions. 
	rooms.push_back(new Room("\nEntrance:\n'We are currently at the Park Entrance':  North - There is a water fountain.  West - There is a SeeSaw"));
	rooms.push_back(new Room("\nWater Fountain: \n'Here we are at the water fountain.  Legends tell of a beautiful mermaid that swims these waters.  North - Ahead you see a Swing set.  East - Several horses on springs.  South - Park Entrance.  West - A Wobbly bridge.'"));
	rooms.push_back(new Room("\nSpring Riders: \n'We have arrived at the Spring Riders!  Be careful around these parts...there sometimes lurks a wild centaur.  Back West is the Entrance.'"));
	rooms.push_back(new Room("\nSwing Set: \n'We are now at the swing set!  Attached to the side is a massive Pirate ship with a treasure chest mounted behind the captain.  Beware ye scallywags for Pete the Pirate is not to be trifled with!  South - Park Entrance.  West - Sandbox.'"));
	rooms.push_back(new Room("\nWobbly Bridge: \n'Careful!  This bridge is the home of the tricky Troll!  North - Sandbox.  West - Park Entrance.'"));
	rooms.push_back(new Room("\nSandbox: \n'Whoa!  Someone has built a fort in the middle of the sandbox!  There is a flap covering the entrance.  I wonder what is inside...  North - Monkey Bars.  East - Swing set.  South - Wobbly Bridge.  West - Merry-Go-Round.'"));
	rooms.push_back(new Room("\nMonkey Bars: \n'Swinging back and forth amoung the bars is a fierce gorilla!  South - Sandbox'"));
	rooms.push_back(new Room("\nMerry-Go-Round: \n'We've made it to the Merry-Go-Round.  A devilish pixie has trapped some other kids on the ride.  She spins it so fast that one boy's backpack goes flying!  A trapper keeper is amoung the items that have escaped.'  East - Sandbox.  South - Slide Entrance.'"));
	rooms.push_back(new Room("\nSlide Entrance: 'Here is one of the entrances to the slide.  It is heavily guarded by cowboys as the Sheriff runs this part of the park.  North - Merry-Go-Round.  East - Seesaw.  South - Slide.'"));
	rooms.push_back(new Room("\nSeeSaw: \n'A giant places his foot on one end of the seesaw while two children are stuck in the air!  East - Park Entrance.  South - Slide Entrance.  West - Slide Entrance.'"));
	rooms.push_back(new Room("\nSlide Entrance: \n'Here is one of the entrances to the slide.  It is heavily guarded by cowboys as the Sheriff runs this part of the park. North - Seesaw.  West - Slide.'"));
	rooms.push_back(new Room("\nSlide: \n'We have fianlly made it to the slide!  The Sheriff is the biggest and meanest guy in town!  Don't let him getcha!'"));


	//The next several lines create the connections from room to room as well as assign individual enemies and items to the room. 
	rooms[0]->setConnections(rooms[1], nullptr, nullptr, rooms[9]);

	rooms[1]->setConnections(rooms[3], rooms[2], rooms[0], rooms[4]);
	rooms[1]->setMermaid(new Mermaid("Mermaid"));
	rooms[1]->addItems("I");
	

	rooms[2]->setConnections(nullptr, nullptr, nullptr, rooms[1]);
	rooms[2]->setCentaur(new Centaur("Centaur"));
	rooms[2]->addItems("N");
	
	rooms[3]->setConnections(nullptr, nullptr, rooms[1], rooms[5]);
	rooms[3]->setPirate(new Pirate("Pirate"));
	rooms[3]->addItems("SPYGLASS");
	rooms[3]->addItems("E");
	
	rooms[4]->setConnections(rooms[5], rooms[1], nullptr, nullptr);
	rooms[4]->setTroll(new Troll("Troll"));
	rooms[4]->addItems("C");
	
	rooms[5]->setConnections(rooms[6], rooms[3], rooms[4], rooms[7]);
	rooms[5]->addItems("BOARD");
	
	rooms[6]->setConnections(nullptr, nullptr, rooms[5], nullptr);
	rooms[6]->setMonkey(new Monkey("Monkey"));
	rooms[6]->addItems("T");
	
	rooms[7]->setConnections(nullptr, rooms[5], rooms[8], nullptr);
	rooms[7]->setPixie(new Pixie("Pixie"));
	rooms[7]->addItems("KEY");
	rooms[7]->addItems("O");
	
	rooms[8]->setConnections(rooms[7], rooms[9], rooms[11], nullptr);
	rooms[8]->setGoblin(new Goblin("Goblin1"));
	
	rooms[9]->setConnections(nullptr, rooms[0], rooms[10], rooms[8]);
	rooms[9]->setGiant(new Giant("Giant"));
	rooms[9]->addItems("R");
	
	rooms[10]->setConnections(rooms[9], nullptr, nullptr, rooms[11]);
	rooms[10]->setGoblin(new Goblin("Goblin2"));
	
	rooms[11]->setConnections(rooms[8], rooms[10], nullptr, nullptr);
	rooms[11]->setBoss(new Boss("Bossy"));

	rooms[8]->setCanLeaveSouth(false);
	rooms[10]->setCanLeaveWest(false);
	currentRoom = rooms[0];
	
	
	//This while loop generates the output of the game. 
	while (userInput != "QUIT") {
		//The next series of if/else statements calls booleans to check if enemy has been defeated.  If they have, they will no longer appear in the room. 
		if (currentRoom == rooms[1]) {
			if (currentRoom->defeated == false) {
				bool check = currentRoom->getMermaid()->iSpy(player.getInventory());
				if (check)
				{
					rooms[1]->defeated = true;
				}
			}
		}
		else if (currentRoom == rooms[2]) {
			if (currentRoom->defeated == false) {
				bool check = currentRoom->getCentaur()->pickGame();
				if (check) {
					rooms[2]->defeated = true;
				}
			}
		}
		else if (currentRoom == rooms[3]) {
			if (currentRoom->defeated == false) {
				bool check = currentRoom->getPirate()->pickGame();
				if (check) {
					rooms[3]->defeated = true;
				}
			}
		}
		else if (currentRoom == rooms[4]) {
			if (currentRoom->defeated == false) {
				bool check = currentRoom->getTroll()->solveTheRiddle(player.getInventory());
				if (check)
				{
					rooms[4]->defeated = true;
				}
			}
		}
		else if (currentRoom == rooms[6]) {
			if (currentRoom->defeated == false) {
				bool check = currentRoom->getMonkey()->pickGame();
				if (check) {
					rooms[6]->defeated = true;
				}
			}
		}
		else if (currentRoom == rooms[7]) {
			if (currentRoom->defeated == false) {
				bool check = currentRoom->getPixie()->pickGame();
				if (check) {
					rooms[7]->defeated = true;
				}
			}
		}
		else if (currentRoom == rooms[8]) {
			if (currentRoom->defeated == false) {
				bool check = currentRoom->getGoblin()->enterPassword();
				if (check)
				{
					rooms[8]->defeated = true;
					rooms[8]->setCanLeaveSouth(true);
				}
			}
		}
		else if (currentRoom == rooms[9]) {
			if (currentRoom->defeated == false) {
				bool check = currentRoom->getGiant()->pickGame();
				if (check) {
					rooms[9]->defeated = true;
				}
			}
		}
		else if (currentRoom == rooms[10]) {
			if (currentRoom->defeated == false) {
				bool check = currentRoom->getGoblin()->enterPassword();
				if (check)
				{
					rooms[10]->defeated = true;
					rooms[10]->setCanLeaveWest(true);
				}
			}
		}
		else if (currentRoom == rooms[11]) {
			currentRoom->getBoss()->finalFight();
		}
		std::cout <<"\n\nEnter command: " << std::endl;
		getline(std::cin, userInput);

		std::size_t space = userInput.find(" ");
		std::string action = userInput.substr(0, space);
		std::string object = userInput.substr(space + 1, userInput.size() - 1);


		//The next if/else statements generate the commands for the game. 
		if (action == "MOVE") {
			if (object == "NORTH" || object == "EAST" || object == "SOUTH" || object == "WEST") {
				currentRoom = currentRoom->getRoom(object);
			}
			else {
				std::cout << "Silly goose!  That's not a direction!" << std::endl;
			}
		}
		else if (action == "LOOK") {
			player.look(currentRoom);
		}
		else if (action == "SEARCH") {
			player.search(currentRoom, rooms, object);
		}
		else if (action == "TAKE") {
			if (currentRoom->checkItems(object)) {
				player.take(object);
				currentRoom->removeItem(object);
			}
			else {
				std::cout << "That won't fit in my backpack!" << std::endl;
			}
		}
		else if (action == "STUFF") {
			std::cout << "\nMy stuff: \n" << std::endl;
			for (std::string e : player.getInventory()) {
				std::cout << e + "\n";
			}
			std::cout << std::endl;
		}
		else if (action == "OPEN") {
			player.open(currentRoom, rooms, object);
		}
		else if (action == "HELP") {
			std::cout << "\nMOVE - Enter 'MOVE' and a direction 'NORTH', 'EAST', 'SOUTH', or 'WEST' to move throughout the park.\nSTUFF - This shows everything in my backpack.\nTAKE - This adds items to my backpack.\nLOOK - This will give you a description of our surroundings.\nOPEN - Some items thoughout the park can be opened. \nSEARCH - This will give you a description of what is inside items." << std::endl;
		}
		else {
			std::cout << "\nSilly goose!  That won't work!  Type 'HELP' for valid commands. " << std::endl;
		}
	}
	
	
	int a;
	std::cin >> a;
}