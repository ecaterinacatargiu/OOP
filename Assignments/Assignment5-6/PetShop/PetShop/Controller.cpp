#include "Controller.h"
#include "Validator.h"
#include <algorithm>

int Controller::addPetToRepo(const std::string breed, const std::string name, const int age, const std::string photo)
{
	Pet pet{ breed, name, age, photo };
	Validator{ pet };
	return this->r->addPet(breed, name, age, photo);
}

int Controller::removePetFromRepo(std::string name)
{
	return this->r->deletePet(name);
}

int Controller::updatePetFromRepo(const std::string breed, const std::string name, const int age, const std::string photo)
{
	Pet pet{ breed, name, age, photo };
	Validator{ pet };
	return this->r->updatePet(name, breed, age, photo);
}

int Controller::getSize()
{
	return this->r->getSize();
}

int Controller::getSizeAdopted()
{
	return this->r->getSizeAdopted();
}

std::vector<Pet> Controller::filterPets(const std::string breed, const int age)
{
	std::vector<Pet> allPets = this->r->getAll();
	std::vector<Pet> filteredPets(allPets.size());
	auto it = std::copy_if(allPets.begin(), allPets.end(),filteredPets.begin(),[&](Pet p) {return ((p.getBreed() == breed || breed == "") && p.getAge() <= age); });
	filteredPets.resize(std::distance(filteredPets.begin(), it));

	return filteredPets;
}

std::vector<Pet> Controller::sortPets(Comparator<Pet>* comp, std::vector<Pet> list)
{
	int size = list.size();
	int i, j;
	for (i = 0; i < size - 1; i++)
		for (j = i + 1; j < size; j++)
		{
			if (!comp->relation(list[i], list[j]))
				std::swap(list[i], list[j]);
		}
	return list;
}

std::vector<Pet> Controller::compareAge()
{
	CompareDescendingByAge *comp = new CompareDescendingByAge;
	std::vector<Pet> list = this->sortPets(comp, this->r->getAll());
	delete comp;
	return list;
}

std::vector<Pet> Controller::compareBreed()
{
	CompareAscendingByBreed *comp = new CompareAscendingByBreed;
	std::vector<Pet> list = this->sortPets(comp, this->r->getAll());
	delete comp;
	return list;
}

void Controller::showAdoptionList()
{
	this->r->showAdoptionList();
}


int Controller::addPetToAdoptionList(Pet p)
{
	this->r->addAdoptionList(p);
	this->r->writeAdoption();
	return 1;
}

std::vector<Pet> Controller::getAll()
{
	return this->r->getAll();
}

std::vector<Pet> Controller::getAllAdopted()
{
	return this->r->getAdopted();
}

/*int Controller::removePetFromAdoptionList(Pet pet)
{
	this->removePetFromAdoptionList(pet);
	return 1;
}*/

Controller::~Controller()
{
}


