#pragma once
#include "Bully.h"

//Pirate inherits from Bully.
class Pirate : Bully
{
public:
	Pirate(std::string name);
	bool pickGame();
};

