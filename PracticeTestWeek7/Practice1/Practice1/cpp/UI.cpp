#include "UI.h"
#include <iostream>
#include <string>

using namespace std;

void UI::startApp()
{
	while (true)
	{
		UI::printMenu();
		int option{ 0 };
		cout << endl;
		cout << "Enter your option: ";
		cin >> option;
		cin.ignore();
		cout << endl;
		if (option == 0)
			break;
		else if (option == 1)
			this->displayPlayers();
		else if (option == 2)
			this->addEhfToRepo();
		else if (option == 3)
			this->sortPlayersByGoals();
		else if (option == 4)
			this->getGoals();
	}

}

void UI::printMenu()
{
	cout << endl;
	cout << "Please choose one of the following options: " << endl;
	cout << "1 - Display players." << endl;
	cout << "2 - Add a new player." << endl;
	cout << "3 - Sort player by goals." << endl;
	cout << "4 - Total goals in a given country." << endl;
	cout << endl;
}

void UI::addEhfToRepo()
{
	cout << "Enter the name: ";
	std::string name;
	getline(cin, name);

	cout << "Enter the nationality: ";
	std::string nationality;
	getline(cin, nationality);

	cout << "Enter the team: ";
	std::string team;
	getline(cin, team);

	int goals = 0;
	cout << "Enter the goals: ";
	cin >> goals;
	cin.ignore();

	this->ctrl.addEhfToRepo(name, nationality, team, goals);
}

void UI::displayPlayers()
{
	DynamicArray da = this->ctrl.getRepo().getEhf();
	EHF* ehf = da.getAll();

	for (int i = 0; i < da.getSize(); i++)
	{
		EHF e = ehf[i];
		cout << e.getName() << ", " << e.getNationality() << ", " << e.getTeam() << ", " << e.getGoals() << " ." << endl;;

	}


}

void UI::sortPlayersByGoals()
{
	DynamicArray da = this->ctrl.getRepo().getEhf();
	EHF* ehf = da.getAll();

	for (int i = 0; i < da.getSize() - 1; i++)
		for (int j = i; j < da.getSize(); j++)
			if (ehf[i].getGoals() < ehf[j].getGoals())
				swap(ehf[i], ehf[j]);

	for (int i = 0; i < da.getSize(); i++)
	{
		EHF e = ehf[i];
		cout << e.getName() << ", " << e.getNationality() << ", " << e.getTeam() << ", " << e.getGoals() << " ." << endl;
	}

}

void UI::getGoals()
{
	int goals = 0;

	DynamicArray da = this->ctrl.getRepo().getEhf();
	EHF* ehf = da.getAll();

	cout << "Enter a nationality: ";
	std::string nat;
	getline(cin, nat);

	for (int i = 0; i < da.getSize(); i++)
		if (ehf[i].getNationality() == nat)
			goals += ehf[i].getGoals();

	cout << goals<<endl;



}
