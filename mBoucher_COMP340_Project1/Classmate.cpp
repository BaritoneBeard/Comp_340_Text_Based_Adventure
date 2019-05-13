#include "Classmate.h"



Classmate::Classmate(std::string name)
{
	this->name = name;
}
//The getters for name and description. 
std::string Classmate::getName() {
	return this->name;
}
std::string Classmate::getDescription() {
	return this->description;
}

