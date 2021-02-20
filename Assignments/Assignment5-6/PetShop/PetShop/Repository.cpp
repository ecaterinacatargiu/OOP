#include "Repository.h"
#include "Validator.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>


int Repository::addPet(const std::string breed, const std::string name, const int age, const std::string photo)
{
	Pet p{ breed, name, age, photo };
	if (std::count(this->pets.begin(), this->pets.end(), p) != 0)
		throw RepositoryException("Pet already exists..");
	this->pets.push_back(p);
	this->updateFile("pets.txt");
	return 1;
}

int Repository::deletePet(std::string & name)
{
	Pet p{ "", name, 0, "" };
	std::vector<Pet>::iterator it = std::find(this->pets.begin(), this->pets.end(), p);
	if (it == this->pets.end())
		throw RepositoryException("Doggie doesn't exist :(");
	this->pets.erase(it);
	this->updateFile("pets.txt");
	return 1;
}

int Repository::updatePet(const std::string name, const std::string breed, const int age, const std::string photo)
{
	Pet p{ name, breed, age, photo };
	std::vector<Pet>::iterator it = std::find(this->pets.begin(), this->pets.end(), p);
	if (it == this->pets.end())
		throw RepositoryException("Dog doesn't exist..");
	int pos = std::distance(this->pets.begin(), it);
	this->pets[pos] = p;
	this->updateFile("pets.txt");
	return 1;
}

void Repository::readFile(const std::string filename)
{
	std::ifstream fin(filename);
	std::string line;
	Pet p;
	while (fin >> p)
	{
		Validator{ p };
		this->pets.push_back(p);
	}
	fin.close();
}

void Repository::updateFile(const std::string filename)
{
	std::ofstream fout(filename);
	for (auto it : this->pets)
	{
		fout << it;
		fout << "\n";
	}
	fout.close();
}

std::vector<Pet> Repository::getAll()
{
	return this->pets;
}

std::vector<Pet> Repository::getAdopted()
{
	return this->addoptionList;
}

int Repository::getSize()
{
	return this->pets.size();
}

int Repository::getSizeAdopted()
{
	return this->addoptionList.size();
}

int Repository::addAdoptionList(Pet pet)
{
	this->addoptionList.push_back(pet);
	std::vector<Pet>::iterator it = std::find(this->pets.begin(), this->pets.end(), pet);
	this->pets.erase(it);
	return 1;
}
