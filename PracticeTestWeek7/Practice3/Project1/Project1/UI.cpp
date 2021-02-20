#include "UI.h"
#include <iostream>
#include <stdlib.h>
#include "Gene.h"

using namespace std;

void UI::Start()
{
	while (true)
	{
		UI::printMenu();
		int option{ 0 };
		cout << endl;
		cout << "Enter an option: ";
		cin >> option;
		cin.ignore();
		cout << endl;
		if (option == 0)
			break;
		else if (option == 1)
			this->displayGenes();
		else if (option == 2)
			this->addGenes();
		else if (option == 3)
			this->sortGenesByOrganism();
		else if (option == 4)
			this->getTheGenes();

	}
}

void UI::printMenu()
{
	cout << endl;
	cout << "1 - List genes" << endl;
	cout << "2 - Add a new gene." << endl;
	cout << "3 - Sort genes by organisms." << endl;
	cout << "4 - Find genes. " << endl;
}

void UI::displayGenes()
{
	DynamicArray v = this->ctrl.getRepo().getGenes();
	Gene* genes = v.getAll();

	for (int i = 0; i < v.getSize(); i++) 
	{
		Gene g = genes[i];
		cout << g.getName() << ", " << g.getOrganism() << ", " << g.getSequence() << "." << endl;
	}
}

void UI::addGenes()
{
	cout << "Enter the name: ";
	std::string name;
	getline(cin, name);
	cout << "Enter the organism: ";
	std::string organism;
	getline(cin, organism);
	cout << "Enter the sequence: ";
	std::string sequence;
	getline(cin, sequence);

	this->ctrl.addGeneToRepo(name, organism, sequence);
}

void UI::sortGenesByOrganism()
{
	DynamicArray da = this->ctrl.getRepo().getGenes();
	Gene* gene = da.getAll();

	for (int i = 0; i < da.getSize() - 1; i++)
		for (int j = i; j < da.getSize(); j++)
			if (gene[i].getOrganism() < gene[j].getOrganism())
				swap(gene[i], gene[j]);

	for (int i = 0; i < da.getSize(); i++)
	{
		Gene g = gene[i];
		cout << g.getName() << ", " << g.getOrganism() << ", " << g.getSequence() << "." << endl;
	}
}

void UI::getTheGenes()
{
	DynamicArray da = this->ctrl.getRepo().getGenes();
	Gene* gene = da.getAll();

	cout << "Enter the sequence: ";
	std::string sequence;
	getline(cin, sequence);


	for (int i = 0; i < da.getSize(); i++)
	{
		Gene gena = gene[i];
		if(gene[i].getOrganism().find(sequence)==0)
			cout << gena.getName() << ", " << gena.getOrganism() << ", " << gena.getSequence() << "." << endl;
			
	}
}
