#pragma once
#include <string>
#include <vector>

//This class is a top-level enemy class. 
class Classmate
{
public:
	Classmate(std::string name);

	std::string getName();
	std::string getDescription();
	

protected:
	std::string name;
	std::string description;
};

