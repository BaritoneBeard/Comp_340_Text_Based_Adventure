#pragma once
#include "Bully.h"

//Giant inherits from Bully.
class Giant : Bully
{
public:
	Giant(std::string name);
	
	bool pickGame();
};

