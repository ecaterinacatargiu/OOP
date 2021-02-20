#include "Appliance.h"
#include <string>

Appliance::~Appliance()
{
}

std::string Appliance::getID()
{
	return this->id;
}

double Appliance::getWeight()
{
	return this->weight;
}

Refrigerator::Refrigerator(std::string energyUsageClass, bool hasFreezer, std::string id, double weight): energyUsageClass{energyUsageClass}, hasFreezer{hasFreezer}
{
	this->id = id;
	this->weight = weight;
}

std::string Refrigerator::getEnergyUsageClass()
{
	return this->energyUsageClass;
}

bool Refrigerator::getFreezer()
{
	return this->hasFreezer;
}

double Refrigerator::consumedEnergy()
{
	double ec, i1 = 3, i2 = 2.5, i3 = 2;
	if (this->getFreezer())
		if (this->getEnergyUsageClass() == "A")
			ec = 30 * i1 + 20;
		else if (this->getEnergyUsageClass() == "A+")
			ec = 30 * i2 + 20;
		else if (this->getEnergyUsageClass() == "A++")
			ec = 30 * i3 + 20;
	else
		if (this->getEnergyUsageClass() == "A")
			ec = 30 * i1;
		else if (this->getEnergyUsageClass() == "A+")
			ec = 30 * i2;
		else if (this->getEnergyUsageClass() == "A++")
			ec = 30 * i3;
	return ec;
}

std::string Refrigerator::toString()
{
	std::string RefrigeratorString = "ID: " + this->getID() + ", " + "Weight: " + std::to_string(this->getWeight()) + ", Energy usage class: " + this->getEnergyUsageClass() + ", Has freezer? " + std::to_string(this->getFreezer());
	return RefrigeratorString;
}

DishWashingMachine::DishWashingMachine(double washingCircleLength, double consumedEnergyForOneHour, std::string id, double weight): washingCircleLength{washingCircleLength}, consumedEnergyForOneHour{consumedEnergyForOneHour}
{
	this->id = id;
	this->weight = weight;
}

double DishWashingMachine::getWshingCircleLength()
{
	return this->getWshingCircleLength();
}

double DishWashingMachine::getConsumedEnergyForOneHour()
{
	return this->getConsumedEnergyForOneHour();
}

double DishWashingMachine::consumedEnergy()
{
	double ec;
	ec = this->getConsumedEnergyForOneHour()*this->getWshingCircleLength() * 8;
	return ec;
}

std::string DishWashingMachine::toString()
{
	std::string DishWaherString = "ID: " + this->getID() + ", " + "Weight: " + std::to_string(this->getWeight()) + ", Washing circle length: " + std::to_string(this->getWshingCircleLength()) + ", Energy consumed for one hour: " + std::to_string(this->getConsumedEnergyForOneHour());
	return DishWaherString;
}