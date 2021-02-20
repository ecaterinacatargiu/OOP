#include "UI.h"
#include <iostream>

using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "You have the following option: " << endl;
	cout << "1-List all apliances" << endl;
	cout << "2-Add a new appliance" << endl;
	cout << "3-Sort appliances" << endl;
	cout << "4-Put into file" << endl;
	cout << endl;
}

void UI::addAppliance()
{
	Appliance* a;
	int input;
	cout << "Enter the kind of appliance you want to add: 1 - Refrigerator and 2 - DishWasher" << endl;
	std::string id;
	double weight;
	cin >> input;
	if (input == 1)
	{
		cout << "ID: ";
		cin >> id;
		cout << "Weight: ";
		cin >> weight;
		std::string electricityUsaceClass;
		bool hasFreezer;
		cout << "Energy usage class: ";
		cin >> electricityUsaceClass;
		cout << "Has freezer? ";
		cin >> hasFreezer;
		a = new Refrigerator(electricityUsaceClass, hasFreezer, id, weight);
	}
	else
	{
		cout << "ID: ";
		cin >> id;
		cout << "Weight: ";
		cin >> weight;
		double washingCircleLength, consumedEnergyForOneHour;
		cout << "Washing circle length(in hours): ";
		cin >> washingCircleLength;
		cout << "Consumed energy for one hour: ";
		cin >> consumedEnergyForOneHour;
		a = new DishWashingMachine(washingCircleLength, consumedEnergyForOneHour, id, weight);
	}
	if (this->ctrl.addAppliance(a))
		cout << "Appliance added succesfully !!" << endl;
	else
		cout << "Appliance cannot be added :( " << endl;
}

void UI::printAppliance()
{
	std::vector<Appliance*> a = this->ctrl.getAll();
	for (auto it : a)
	{
		cout << it->toString() << "\n";
	}
}

void UI::sortAppliances()
{
	std::vector<Appliance*> a = this->ctrl.getAll();
	for (int i = 0; i < a.size() - 1; i++)
		for (int j = i + 1; j < a.size(); j++)
			if (a[i]->getWeight() < a[j]->getWeight())
				swap(a[i], a[j]);
	for (auto it : a)
	{
		cout << it->toString() << "\n";
	}
}

void UI::putIntoFile()
{
	double maxEnergy;
	cout << "Max energy allowed: ";
	cin >> maxEnergy;

	this->ctrl.getAllWithConsumedEnergyLessThan(maxEnergy);
}

void UI::start()
{
	int input;
	while (true) 
	{
		UI::printMenu();
		cin >> input;
		if (input == 1)
			this->printAppliance();
		else if (input == 2)
			this->addAppliance();
		else if (input == 3)
			this->sortAppliances();
		else if (input == 4)
			this->putIntoFile();
		else break;
	}
}
