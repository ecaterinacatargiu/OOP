#pragma once
#include "Pet.h"
#include <vector>
#include <algorithm>

class Repository
{
private:

	std::vector<Pet> pets{};
	std::vector<Pet> addoptionList{};

public:
	Repository() {};

	int addPet(const std::string breed, const std::string name, const int age, const std::string photo);
	int deletePet(std::string& name);
	int updatePet(const std::string name, const std::string breed, const int age, const std::string photo);

	void readFile(const std::string filename);
	void updateFile(const std::string filename);

	std::vector<Pet> getAll();
	std::vector<Pet> getAdopted();

	int getSize();
	int getSizeAdopted();

	int addAdoptionList(Pet p);

	virtual void writeAdoption() = 0;
	virtual void showAdoptionList() = 0;

	virtual ~Repository() {}
};


