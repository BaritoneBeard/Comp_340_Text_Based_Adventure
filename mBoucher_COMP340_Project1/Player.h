#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Room.h"

class Player
{
public:
	Player();

	//The following lines are initializing the command methods.
	void take(std::string singleItem);
	void removeItem(std::string singleItem);
	std::vector<std::string> getInventory();
	void search(Room* room, std::vector<Room*> rooms, std::string openItem);
	void open(Room* room, std::vector<Room*> rooms, std::string openItem);
	void look(Room* room);
	void listInventory();

protected:
	std::vector<std::string > inventory;
	std::string singleItem;
	std::string openItem;
	
	
};
