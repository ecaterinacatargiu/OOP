#include "Controller.h"
#include <iterator>
#include <vector>
#include<fstream>
#include <sstream>

bool Controller::checkifItExists(std::string id, double weight)
{
	for (auto it : this->appliances)
		if (it->getID()==id && it->getWeight()==weight)
			return true;
	return false;
}

std::vector<Appliance*> Controller::getAll()
{
	return this->appliances;
}

void Controller::updateFile(std::string filename)
{
	std::vector<Appliance*> v;
	std::ofstream fout(filename);
	for (auto it : v)
	{
		fout << it->toString();
		fout << "\n";
	}
	fout.close();
}

bool Controller::addAppliance(Appliance * a)
{
	if (checkifItExists(a->getID(), a->getWeight()) == true)
		return false;
	else
		this->appliances.push_back(a);
}

std::vector<Appliance*> Controller::getAllWithConsumedEnergyLessThan(double maxEnergy)
{

	std::vector<Appliance*> demo{};
	for (auto it : this->appliances)
	{
		if (it->consumedEnergy() < maxEnergy)
			demo.push_back(it);
	}
	this->updateFile("Energy.txt");
	return demo;
}

Controller::~Controller()
{
}
