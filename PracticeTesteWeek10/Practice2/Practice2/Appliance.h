#pragma once
#include <string>

class Appliance
{
protected:
	std::string id;
	double weight;

public:
	Appliance() {}
	virtual ~Appliance();

	std::string getID();
	double getWeight();

	virtual double consumedEnergy() = 0;
	virtual std::string toString() = 0;

};

class Refrigerator: public Appliance
{
private:
	std::string energyUsageClass;
	bool hasFreezer;

public:
	Refrigerator(std::string energyUsageClass, bool hasFreezer, std::string id, double weight);

	std::string getEnergyUsageClass();
	bool getFreezer();

	double consumedEnergy();
	std::string toString();
};

class DishWashingMachine : public Appliance 
{
private:
	double washingCircleLength;
	double consumedEnergyForOneHour;

public:
	DishWashingMachine(double washingCircleLength, double consumedEnergyForOneHour, std::string id, double weight);

	double getWshingCircleLength();
	double getConsumedEnergyForOneHour();

	double consumedEnergy();
	std::string toString();

};