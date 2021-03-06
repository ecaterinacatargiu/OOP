#include "Pet.h"
#include <string>
#include <Windows.h>
#include <shellapi.h>
#include <vector>
#include "Validator.h"
#include <stdlib.h>
#include <iostream>


using namespace std;

Pet::~Pet()
{
}

//Getters for the breed, name, age and photo
std::string Pet::getBreed()
{
	return this->breed;
}

std::string Pet::getName()
{
	return this->name;
}

int Pet::getAge()
{
	return this->age;
}

std::string Pet::getPhoto()
{
	return this->photo;
}


//Operator == implementation
bool Pet::operator==(Pet pet)
{
	if (this->getBreed() == pet.getBreed() && this->getName() == pet.getName() && this->getPhoto() == pet.getPhoto())
		return true;
	return false;
}


//showing the photo
void Pet::show()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getPhoto().c_str(), NULL, SW_SHOWMAXIMIZED);
}


std::string Pet::toString()
{
	std::string petString = "Breed: " + this->getBreed() + ", Name: " + this->getName() + ", Age: " + std::to_string(this->getAge()) + ", Photo: " + this->getPhoto();
	return petString;
}

std::string Pet::writeDog()
{
	std::string petString = this->getName() + " " + this->getBreed() + " " + std::to_string(this->getAge()) + " " + this->getPhoto();
	return petString;
}

std::ostream & operator<<(std::ostream & out, Pet & p)
{
	out << p.breed << " " << p.name << " " << p.age << " " << p.photo;
	return out;
}

std::istream & operator>>(std::istream & in, Pet & p)
{
	in >> p.breed >> p.name >> p.age >> p.photo;
	return in;
}

Pet PetMaker::createPet(const std::string & breed, const std::string & name, int & age, const std::string & photo)
{
	std::string errors = "";
	std::string breedP = "";
	std::string nameP = "";
	std::string photoP = "";
	int age = std::stoi(age);
	try
	{
		breedP = Validator::
	}
}
