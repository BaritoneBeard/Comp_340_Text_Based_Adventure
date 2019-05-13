#pragma once
#include "Monkey.h"
#include "Pirate.h"
#include "Giant.h"
#include "Pixie.h"
#include "Centaur.h"
#include "Troll.h"
#include "Mermaid.h"
#include "Goblin.h"
#include "Boss.h"
#include <string>
#include <vector>
class Room
{
public:
	Room(std::string description);
	~Room();

	std::string getDescription();
	
	//this method initializes the mapping of the rooms.
	void setConnections(Room* northRoom, Room* eastRoom, Room* southRoom, Room* westRoom);

	Room* getRoom(std::string direction);

	//the next several methods initialize the individual enemies.
	void setMonkey(Monkey* monkey);
	void setPirate(Pirate* pirate);
	void setGiant(Giant* giant);
	void setPixie(Pixie* pixie);
	void setCentaur(Centaur* centaur);
	void setTroll(Troll* troll);
	void setMermaid(Mermaid* mermaid);
	void setGoblin(Goblin* goblin);
	void setBoss(Boss* boss);

	Monkey* getMonkey();
	Pirate* getPirate();
	Giant* getGiant();
	Pixie* getPixie();
	Centaur* getCentaur();
	Troll* getTroll();
	Mermaid* getMermaid(); 
	Goblin* getGoblin();
	Boss* getBoss();

	//the next several methods are used as checks throughout the game. 
	bool isDefeated();
	void setCanTake();
	bool getCanTake();
	void setCheckOpen();
	bool getCheckOpen();
	std::vector<std::string> getItems();
	void addItems(std::string individualItem);
	bool checkItems(std::string individualItem);
	void removeItem(std::string singleItem);
	bool defeated = false;
	void setCanLeaveWest(bool canLeave);
	void setCanLeaveSouth(bool canLeave);
	bool getCanLeaveWest();
	bool getCanLeaveSouth();



private:
	std::vector<std::string > items;
	std::string description;

	Room* northRoom;
	Room* eastRoom;
	Room* southRoom;
	Room* westRoom;

	Monkey* monkey;
	Pirate* pirate;
	Giant* giant;
	Pixie* pixie;
	Centaur* centaur;
	Troll* troll;
	Mermaid* mermaid;
	Goblin* goblin;
	Boss* boss;

	
	bool canTake = false;
	bool checkOpen = false;
	bool canLeaveSouth = true;
	bool canLeaveWest = true;
};

