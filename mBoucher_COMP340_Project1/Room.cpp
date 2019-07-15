#include "Room.h"



Room::Room(std::string description)
{
	this->description = description;
}

std::string Room::getDescription() {
	return this->description;
}

void Room::setConnections(Room* northRoom, Room* eastRoom, Room* southRoom, Room* westRoom) {
	this->northRoom = northRoom;
	this->eastRoom = eastRoom;
	this->southRoom = southRoom;
	this->westRoom = westRoom;
}

void Room::setMonkey(Monkey* monkey) {
	this->monkey = monkey;
}
void Room::setPirate(Pirate* pirate) {
	this->pirate = pirate;
}
void Room::setGiant(Giant* giant) {
	this->giant = giant;
}
void Room::setPixie(Pixie* pixie) {
	this->pixie = pixie;
}
void Room::setCentaur(Centaur* centaur) {
	this->centaur = centaur;
}
void Room::setTroll(Troll* troll) {
	this->troll = troll;
}
void Room::setMermaid(Mermaid* mermaid) {
	this->mermaid = mermaid;
}
void Room::setGoblin(Goblin* goblin) {
	this->goblin = goblin;
}
void Room::setBoss(Boss* boss) {
	this->boss = boss;
}

Monkey* Room::getMonkey() {
	return this->monkey;
}
Pirate* Room::getPirate() {
	return this->pirate;
}
Giant* Room::getGiant() {
	return this->giant;
}
Pixie* Room::getPixie() {
	return this->pixie;
}
Centaur* Room::getCentaur() {
	return this->centaur;
}
Troll* Room::getTroll() {
	return this->troll;
}
Mermaid* Room::getMermaid() {
	return this->mermaid;
}
Goblin* Room::getGoblin() {
	return this->goblin;
}
Boss* Room::getBoss() {
	return this->boss;
}

bool Room::isDefeated() {
	if (defeated) {
		return true;
	}
}

Room* Room::getRoom(std::string direction) {
	if (direction =="NORTH" && this->northRoom != nullptr) {
		std::cout << northRoom->getDescription() << std::endl;
		return this->northRoom;
	}
	else if (direction == "EAST" && this->eastRoom != nullptr) {
		std::cout << eastRoom->getDescription() << std::endl;
		return this->eastRoom;
	}
	else if (direction == "SOUTH" && this->southRoom != nullptr && this->canLeaveSouth == true) {
		std::cout << southRoom->getDescription() << std::endl;
		return this->southRoom;
	}
	else if (direction == "WEST" && this->westRoom != nullptr && this->canLeaveWest == true) {
		std::cout << westRoom->getDescription() << std::endl;
		return this->westRoom;
	}
	else {
		return this;
	}
}

std::vector<std::string> Room::getItems() {
	return this->items;
}
void Room::addItems(std::string individualItem) {
	items.push_back(individualItem);
}
bool Room::checkItems(std::string individualItem) {
	int index = 0;
	for (std::string e : items) {
		if (e == individualItem) {
			return true;
		}
		index++;
	}
	return false;
}

void Room::removeItem(std::string singleItem) {
	int index = 0;
	for (std::string e : items) {
		if (e == singleItem) {
			this->items.erase(this->items.begin() + index);
		}
		index++;
	}
}

void Room::setCanTake()
{
	this->canTake = true;
}
	
	
bool Room::getCanTake()
{
	return this->canTake;
}

void Room::setCheckOpen() {
	this->checkOpen = true;
}
bool Room::getCheckOpen() {
	return this->checkOpen;
}

void Room::setCanLeaveWest(bool canLeave) {
	this->canLeaveWest = canLeave;
}
void Room::setCanLeaveSouth(bool canLeave) {
	this->canLeaveSouth = canLeave;
}

bool Room::getCanLeaveWest() {
	return this->canLeaveWest;
}
bool Room::getCanLeaveSouth() {
	return this->canLeaveSouth;
}