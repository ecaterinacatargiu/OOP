#include "Project.h"

EHF::EHF() : name{ "" }, nationality{ "" }, team{ "" }, goals(0)
{
}

EHF::EHF(const std::string & name, const std::string & n, const std::string & t, const int & g) :
	name{ name }, nationality{ n }, team{ t }, goals{ g }
{
	this->name = name;
	this->nationality = nationality;
	this->team = team;
	this->goals = goals;

}

EHF::~EHF()
{
}

std::string EHF::getName()
{
	return this->name;
}

std::string EHF::getNationality()
{
	return this->nationality;
}

std::string EHF::getTeam()
{
	return this->team;
}

int EHF::getGoals()
{
	return this->goals;
}

void EHF::setName(std::string newName)
{
	this->name = newName;
}

void EHF::setNationality(std::string newNationality)
{
	this->nationality = newNationality;
}

void EHF::setTeam(std::string newTeam)
{
	this->team = newTeam;
}

void EHF::setGoals(int newGoals)
{
	this->goals = newGoals;
}

std::string EHF::toString()
{
	std::string myString(this->name + "\n");
	myString.append(this->nationality + "\n");
	myString.append(this->team + "\n");
	myString.append(this->goals + "\n");

	return myString;
}

int EHF::operator==(EHF ehf)
{
	return this->getName().compare(ehf.getName()) == 0 && this->getNationality().compare(ehf.getNationality()) == 0 && this->getTeam().compare(ehf.getTeam()) == 0;
}

int EHF::operator<(EHF ehf)
{
	return this->getGoals() < ehf.getGoals();
}
