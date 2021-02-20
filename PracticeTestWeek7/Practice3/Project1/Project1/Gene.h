#pragma once
#include "DynamicArray.h"
#include <stdlib.h>
#include <string>

class Gene
{
private:
	std::string name;
	std::string organism;
	std::string sequence;

public:

	Gene();
	Gene(const std::string& name, const std::string& organism, const std::string& sequence);

	std::string getName();
	std::string getOrganism();
	std::string getSequence();

	void setName(std::string newName);
	void setOrganism(std::string newOrganism);
	void setSequence(std::string newSequence);

	std::string toString();

	int operator==(Gene gene);
	int operator<(Gene gene);


};