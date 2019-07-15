#pragma once
#include <string>
#include <iostream>
#include "Classmate.h"

//Troll inherits from Classmate.
class Troll : Classmate
{
public:
	Troll(std::string name);
	
	bool solveTheRiddle(std::vector<std::string > inventory);

private:
	bool haveBoard;
	bool haveKey;
};