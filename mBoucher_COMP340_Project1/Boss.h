#pragma once
#include "Bully.h"
#include <stdlib.h>
//Boss inherits from Bully
class Boss : public Bully
{
public:
	Boss(std::string name);
	~Boss();

	void finalFight();
};
