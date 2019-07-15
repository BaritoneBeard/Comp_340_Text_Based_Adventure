#include "Player.h"

Player::Player()
{
}

void Player::take(std::string singleItem) {
	inventory.push_back(singleItem);
}

void Player::removeItem(std::string singleItem) {
	int index = 0;
	for (std::string e : inventory) {
		if (e == singleItem) {
			this->inventory.erase(this->inventory.begin() + index);
		}
		index++;
	}
}

std::vector<std::string> Player::getInventory() {
	return this->inventory;
}

void Player::search(Room* room, std::vector<Room*> rooms, std::string openItem) {
	int currentRoom = -1;

	for (int i = 0; i < rooms.size(); i++) {
		if (room == rooms[i]) {
			currentRoom = i;
		}
	}
	switch (currentRoom) {
	case 0:
		std::cout << "\nNo silly!  You can't search that!" << std::endl;
		break;
	case 1:
		std::cout << "\nNo silly!  You can't search that!" << std::endl;
		break;
	case 2:
		std::cout << "\nNo silly!  You can't search that!" << std::endl;
		break;
	case 3:
		if (openItem.find("TREASURE CHEST") != std::string::npos && room->getCheckOpen()) {
			std::cout << "\nInside the treasure chest, so carefully wrapped, is the Captain's spyglass." << std::endl;
		}
		break;
	case 4:
		std::cout << "\nNo silly!  You can't search that!" << std::endl;
		break;
	case 5:
		if (openItem.find("FORT") != std::string::npos && room->getCheckOpen()) {
			std::cout << "\nSomeone is working very hard on this fort.  Around you are spare boards, some paint, and bits of ripped cardboard." << std::endl;
		}
		break;
	case 6:
		std::cout << "\nNo silly!  You can't search that!" << std::endl;
		break;
	case 7:
		if (openItem.find("TRAPPER KEEPER") != std::string::npos && room->getCheckOpen()) {
			std::cout << "\nThis sure is a trapper key-per!  There is a key attached to a Mickey Mouse keychain." << std::endl;
		}
		break;
	case 8:
		std::cout << "No silly!  You can't search that!" << std::endl;
		break;
	case 9:
		std::cout << "No silly!  You can't search that!" << std::endl;
		break;
	case 10:
		std::cout << "No silly!  You can't search that!" << std::endl;
		break;
	case 11:
		std::cout << "No silly!  You can't search that!" << std::endl;
		break;
	}
}

void Player::open(Room* room, std::vector<Room*> rooms, std::string openItem) {
	if (room == rooms[3] && openItem == "TREASURE CHEST")
	{
		std::cout << "Treasure chest is open." << std::endl;
		room->setCanTake();
		room->setCheckOpen();
	}
	if (room == rooms[5] && openItem == "FLAP")
	{
		std::cout << "The flap to the fort is open and you crawl inside." << std::endl;
		room->setCanTake();
		room->setCheckOpen();
	}
	if (room == rooms[7] && openItem == "TRAPPER KEEPER")
	{
		std::cout << "The trapper keeper is unzipped." << std::endl;
		room->setCanTake();
		room->setCheckOpen();
	}
}
void Player::look(Room* room) {
	std::cout << room->getDescription() << std::endl;
}

void Player::listInventory() {
	for (std::string e : inventory) {
		std::cout << e + " ";
	}
	std::cout << std::endl;
}
