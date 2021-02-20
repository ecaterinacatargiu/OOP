#pragma once
#include <iterator>
#include <vector>
#include "Building.h"


class Controller 
{
private:
	std::vector<Building*> buildings{};

public:
	Controller() {}

	bool checkIfItExists(std::string adress);
	std::vector<Building*> getAll();

	void updateFile(std::string filename, std::vector<Building*>v);

	bool addBuilding(Building* b);
	std::vector<Building*> getAllToBeDemolished();
	std::vector<Building*> getAllToBeRestored();

	~Controller();
};
