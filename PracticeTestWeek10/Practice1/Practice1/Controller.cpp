#include "Controller.h"
#include <algorithm>
#include <iterator>
#include <fstream>
#include <sstream>



bool Controller::checkIfItExists(std::string adress)
{
	for (auto it : this->buildings)
		if (it->getAdress() == adress)
			return true;
	return false;
}

std::vector<Building*> Controller::getAll()
{
	return this->buildings;
}

/*void Controller::readFile(const std::string filename)
{
	std::ifstream fin(filename);
	std::string line;
	Building* b;
	while (fin >> b)
	{
		this->buildings.push_back(b);
	}
	fin.close();
}*/

void Controller::updateFile(std::string filename, std::vector<Building*>v)
{
	std::ofstream fout(filename);
	for (auto it : v)
	{
		fout << it->toString();
		fout << "\n";
	}
	fout.close();
}

bool Controller::addBuilding(Building* b)
{
	if (checkIfItExists(b->getAdress()) == true)
		return false;
	else
		this->buildings.push_back(b);
		
}

std::vector<Building*> Controller::getAllToBeDemolished()
{
	std::vector<Building*>demo{};
	for (auto it : this->buildings)
	{
		if (it->canBeDemolished())
			demo.push_back(it);
	}
	this->updateFile("ToBeDemolished.txt", demo);
	return demo;
}

std::vector<Building*> Controller::getAllToBeRestored()
{
	std::vector<Building*>demo{};
	for (auto it : this->buildings)
	{
		if (it->mustBeRestored())
			demo.push_back(it);
	}
	this->updateFile("ToBeRestored.txt", demo);
	return demo;
}


Controller::~Controller()
{
}
