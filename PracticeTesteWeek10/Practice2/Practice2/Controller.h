#pragma once
#include <iterator>
#include <vector>
#include "Appliance.h"

class Controller
{
private:
	std::vector<Appliance*> appliances{};

public:
	Controller() {}

	bool checkifItExists(std::string id, double weight);
	std::vector<Appliance*> getAll();

	void updateFile(std::string filename);

	bool addAppliance(Appliance* a);
	std::vector<Appliance*> getAllWithConsumedEnergyLessThan(double maxEnergy);

	~Controller();

};
