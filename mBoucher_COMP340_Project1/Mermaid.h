#pragma once
#include "Classmate.h"
#include <iostream>

//Mermaid inherits from Classmate.
class Mermaid : Classmate
{
public:
	Mermaid(std::string name);
	bool iSpy(std::vector<std::string > inventory);

private:
	bool haveSpy;
};


