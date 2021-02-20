#include "UI.h"
#include <string>
#include <iostream>

using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "You have the following options: " << endl;
	cout << "1 - List all buildings" << endl;
	cout << "2 - Add a new building" << endl;
	cout << "3 - List all buildings sorted by year of construction." << endl;
	cout << "4 - Save the buildings to be restored to file" << endl;
	cout << "5 - Save the buildings to be demolished to another file" << endl;
	cout << endl;
}

void UI::addBuilding()
{
	Building* b;
	int input;
	cout << "Enter the building data: 1 - Block and 2 - House" << endl;
	std::string adress;
	int year;
	cin >> input;
	if (input == 1)
	{
		int totAp, ocAp;
		cout << "Adress: ";
		cin >> adress;
		cout << "Year: ";
		cin >> year;
		cout << "Total ap: ";
		cin >> totAp;
		cout << "Oc sp: ";
		cin >> ocAp;
		b = new Block(totAp, ocAp, adress, year);
	}
	else
	{
		std::string type;
		bool isH;
		cout << "Adress: ";
		cin >> adress;
		cout << "Year: ";
		cin >> year;
		cout << "Type: ";
		cin >> type;
		cout << "Is historical? ";
		cin >> isH;
		b = new House(type, isH, adress, year);
	}

	if (this->ctrl.addBuilding(b))
		cout << "Building added succesfully!" << endl;
	else
		cout << "Building cannot be added :(";
}

void UI::printBuilding()
{
	std::vector<Building*> b = this->ctrl.getAll();
	for (auto it : b)
	{
		cout << it->toString() << "\n";
	}
}

void UI::sortBuildings()
{
	std::vector<Building*> b = this->ctrl.getAll();
	for (int i = 0; i < b.size()-1; i++)
		for (int j = i + 1; j < b.size(); j++)
			if (b[i]->getYear() < b[j]->getYear())
				swap(b[i], b[j]);
	for (auto it : b)
	{
		cout << it->toString() << "\n";
	}
}

void UI::getAllDemolished()
{
	this->ctrl.getAllToBeDemolished();
}

void UI::getAllRestored()
{
	this->ctrl.getAllToBeRestored();
}

void UI::start()
{
	int input;
	while (true)
	{
		UI::printMenu();
		cin >> input;
		if (input == 1)
			this->printBuilding();
		else if (input == 2)
			this->addBuilding();
		else if (input == 3)
			this->sortBuildings();
		else if (input == 4)
			this->getAllRestored();
		else if (input == 5)
			this->getAllDemolished();
		else
			break;
	}
}


