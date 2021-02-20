#include "UI.h"
#include <string>
#include <iostream>
#include "Validator.h"

using namespace std;

void UI::start()
{
	string input;
	while (true)
	{
		cout << "Welcome to Cati's shelter! " << endl;
		cout << endl;
		cout << "Please choose an operating mode: \n";
		UI::printMenu();
		cout << "Option(a for administrator mmode and u for user mode): ";
		cin >> input;
		if (input == "a")
			this->startAdministratorMode();
		else if (input == "u")
			this->startUserMode();
		else if (input == "0")
			break;
	}
}

UI::~UI()
{
}

void UI::printMenu()
{
	cout << endl;
	cout << "1 - Administrator Mode" << endl;
	cout << "2 - User mode." << endl;
	cout << "0 - Exit." << endl;
}

void UI::printAdminMenu()
{
	cout <<endl;
	cout << "ADMINISTRATOR MODE" << endl;
	cout << "You have the following available commands: " << endl;
	cout << "\t1 - List all doggies." << endl;
	cout << "\t2 - Add a dog. " << endl;
	cout << "\t3 - Remove a dog. " << endl;
	cout << "\t4 - Update a dog. " << endl;
	cout << "\t5 - Show photos. " << endl;
	cout << "\t0 - Exit. " << endl;
}

void UI::printUserMenu()
{
	cout << endl;
	cout << "USER MODE" << endl;
	cout << "Y0u have the following available options: " << endl;
	cout << "\t1 - See all doggies. " << endl;
	//cout << "\t2 - Add a dog to the aoption list. " << endl;
	//cout << "\t3 - Remove a dog from the adoption list. " << endl;
	cout << "\t2 - See all  dogs of a given breed, with age less than.. " << endl;
	cout << "\t3 - See the adoption list. " << endl;
	cout << "\t4 - Show adoption list. " << endl;
	cout << "\t0 - Exit. " << endl;
}

void UI::startUserMode()
{
	printUserMenu();
	string input;
	while (true)
	{
		cout << "Option: ";
		input = "";
		cin >> input;
		if (input == "1")
			this->listPets();
		if (input == "2")
			this->filteredAdoption();
		if (input == "3")
			this->listAdoption();
		if (input == "4")
			this->displayAdoption();
		if (input == "0")
			break;
	}
}

void UI::startAdministratorMode()
{
	printAdminMenu();
	string input;
	while (true)
	{
		cout << "Option: ";
		cin >> input;
		if (input == "1")
			this->listPets();
		if (input == "2")
			this->addPettoRepo();
		if (input == "3")
			this->removePetFromRepo();
		if (input == "4")
			this->updatePetFromRepo();
		if (input == "0")
			break;
	}
}

void UI::addPettoRepo()
{
	string breed, name, ageString, photo;
	int age;
	int result;
	cout << "Breed: ";
	cin >> breed;
	cout << "Name: ";
	cin >> name;
	cout << "Age: ";
	cin >> ageString;
	cout << "Photograph: ";
	cin >> photo;
	try
	{
		age = stoi(ageString);
		result = this->ctrl.addPetToRepo(name, breed, age, photo);
		if (result == -1)
			cout << "Dog already exist!\n";
	}
	catch (RepositoryException r)
	{
		result = -1;
		cout << "Repository exception!\n";
	}
	catch (PetException p)
	{
		result = -1;
		cout << p.what();
	}
	catch (...)
	{
		result = -1;
		cout << "Invalid input!\n";
	}
	if (result == 1)
		cout << "Dog added.\n";
}

void UI::removePetFromRepo()
{
	cout << "Yayyy! Another dog will be adopted !! Enter the name: ";
	string name;
	int result;
	cout << "Name: ";
	cin >> name;
	try
	{
		result = this->ctrl.removePetFromRepo(name);
	}
	catch (RepositoryException r)
	{
		result = -1;
		cout << "Repository exception.\n";
	}
	catch (PetException p)
	{
		result = -1;
		cout << p.what();
	}
	if (result == -1)
		cout << "The pet that you are looking for does not exist.";
	else
		cout << "Dog adopted! <3";

}

void UI::updatePetFromRepo()
{
	string breed, name, ageString, photo;
	int age;
	int result;
	cout << "Old breed: ";
	cin >> breed;
	cout << "Old name: ";
	cin >> name;
	cout << "New age: ";
	cin >> ageString;
	cout << "New photograph: ";
	cin >> photo;
	try
	{
		age = stoi(ageString);
		result = this->ctrl.updatePetFromRepo(breed, name, age, photo);
		if (result == -1)
			cout << "Dog doesn't exist!\n";
	}
	catch (RepositoryException r)
	{
		result = -1;
		cout << "Repository exception\n";
	}
	catch (PetException p)
	{
		result = -1;
		cout << p.what();
	}
	catch(...)
	{
		result = -1;
		cout << "Invalid input!\n";
	}
	if (result == 1)
		cout << "Doggie updated.\n";

}

void UI::displayPets()
{
	cout << "Doggies: \n";
	std::vector<Pet> pets = this->ctrl.getAll();
	int size = this->ctrl.getSize();
	cout << "The dogs are:\n";
	for (int i = 0; i < size; ++i)
	{
		cout << pets[i].toString() << "\n";
	}
}

void UI::listPets()
{
	cout << "The dogs available for adoption are:\n";
	int i = 0;
	string input;
	bool adopted;
	while (i < this->ctrl.getSize())
	{
		input = "a";
		Pet p = this->ctrl.getAll()[i];
		adopted = false;
		cout << p.toString();
		cout << "\nDo you want to adopt this dog?(y/n)\n";
		while (input != "y" && input != "n")
			cin >> input;
		if (input == "y")
		{
			this->ctrl.addPetToAdoptionList(p);
			adopted = true;
		}
		cout << "See next?(y/n)\n";
		input = "a";
		while (input != "y" && input != "n")
			cin >> input;
		if (input == "y" && adopted == false)
		{
			i = (i + 1) % this->ctrl.getSize();
		}
		else if (input == "n")
			break;
	}
}

void UI::filteredAdoption()
{
	string breed;
	int age;
	getline(cin, breed);
	cout << "Breed(leave empty for any breed): ";
	cin >> breed;
	cout << "Max age: ";
	cin >> age;
	cout << "The dogs available for adoption are:\n";
	int i = 0;
	string input;
	bool adopted;
	while (i < this->ctrl.filterPets(breed, age).size())
	{
		input = "a";
		Pet p = this->ctrl.filterPets(breed, age)[i];
		adopted = false;
		cout << p.toString();
		//d.displayImage();
		cout << "\nDo you want to adopt this dog?(y/n)\n";
		while (input != "y" && input != "n")
			cin >> input;
		if (input == "y")
		{
			this->ctrl.addPetToAdoptionList(p);
			adopted = true;
		}
		cout << "See next?(y/n)\n";
		input = "a";
		while (input != "y" && input != "n")
			cin >> input;
		if (input == "y" && adopted == false)
		{
			i = (i + 1) % this->ctrl.filterPets(breed, age).size();
		}
		else if (input == "n")
			break;
	}
}

void UI::listAdoption()
{
	std::vector<Pet> pets= this->ctrl.getAllAdopted();
	int size = this->ctrl.getSizeAdopted();
	cout << "The adopted dogs are:\n";
	for (int i = 0; i < size; ++i)
	{
		cout << pets[i].toString() << "\n";
	}
}

void UI::displayAdoption()
{
	this->ctrl.showAdoptionList();
}
