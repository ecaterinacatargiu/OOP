#include "Tests.h"
#include "Pet.h"
#include "Repository.h"
#include "Controller.h"
#include "UI.h"
#include <iostream>
#include <cassert>

/*void Tests::testDA()
{
	DynamicArray da1{ 1 };
	Pet p1{ "Labrador", "Aki", 3, "photo1" };
	Pet p2{ "Akita", "Hanah", 1, "photo2" };
	Pet p3{ "Huski", "Lio", 4, "photo3" };

	da1.add(p1);
	da1.add(p2);

	assert(da1.getAll()[0] == p1);
	assert(da1.getAll()[1] == p2);

	DynamicArray da2 { da1 };
	da1 = da1;
	da2 = da1;

	assert(da2.getSize() == 2);

	//da2 - da1;
	da2 = da1;
	da2.update(1, p1);
	assert(da2.getAll()[1] == p1);

}

void Tests::testPet()
{
	Pet p1{ "Chuaua", "Lena", 2, "photo4" };
	std::string p = p1.toString();
	std::string p2 = "Breed1\nName1\nAge1\nPhoto1\n\n";
	assert(p == p2);
}

void Tests::testRepo()
{
	Repository repo{};
	std::string b1{ "Breed1" };
	std::string n1{ "Name1" };
	//std::string p1{ "Photo1" };
	Pet p1{b1, n1, 2, "photo1"};
	repo.addPet(p1);

	assert(repo.findPetPositionByName(n1) == p1);
	assert(repo.deletePet("Name1") == 1);

	repo.addPet(p1);
	p1 = Pet{ b1, n1, 2, "photo2" };
	repo.updatePet(b1, n1, 2, "photo2");
	repo.updatePet(n1, b1, 2, "photo2");

	assert(repo.getPets().getAll()[0] == p1);
	assert(repo.findPetPosition(n1) == -1);
}

void Tests::testCtrl()
{
	Repository repo;
	Controller ctrl{ repo };

	std::string b1{ "Breed1" };
	std::string n1{ "Name1" };
	std::string ph1{ "photo1" };

	Pet p1{ b1,n1,2,"photo1" };

	ctrl.addPetToAdoptionList(p1);
	ctrl.addPetToRepo(b1, n1, 2, ph1);

	assert(ctrl.getAdoptionList().get(0) == p1);

	ctrl.addPetToRepo(b1, n1, 2, ph1);
	ph1 = std::string{ "photo2" };

	ctrl.updatePetFromRepo(b1, n1, 2, ph1);
	ctrl.removePetFromAdoptionList(p1);
	assert(ctrl.getAdoptionList().size() == 0);

}

void Tests::testAdoptionList()
{
	AdoptionList adoptionList;

	assert(adoptionList.size() == 0);

	Pet p1{ "Breed1", "Name1", 2, "photo1" };
	adoptionList.addPet(p1);

	assert(adoptionList.get(0) == p1);
	assert(adoptionList.get(-1) == Pet{});

	adoptionList.removePet(p1);
	
	assert(adoptionList.get(0) == Pet{});

}

void Tests::runTests()
{
	this->testDA();
	this->testPet();
	this->testRepo();
	this->testCtrl();
	this->testAdoptionList();
}*/
