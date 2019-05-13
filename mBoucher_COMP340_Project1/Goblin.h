#pragma once
#include <string>
#include <iostream>
#include "Classmate.h"

//Goblin inherits from Bully.
class Goblin : Classmate
{
public:
	Goblin(std::string name);

	bool enterPassword();

private:
	bool havePassword = false;
};