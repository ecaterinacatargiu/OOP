#pragma once
#include <Windows.h>
#include <string>
#include <iostream>
#include <shellapi.h>

class Pet
{
private:
	std::string breed;
    std::string name;
	int age;
	std::string photo;

public:
	Pet() : breed{ "" }, name{ "" }, age{ 0 }, photo{ "" }{}
	Pet(const std::string breed, const std::string name, const int age, const std::string photo) :
		breed{ breed }, name{ name }, age{ age }, photo{ photo } {};

	~Pet();

	std::string getBreed();
	std::string getName();
	int getAge();
	std::string getPhoto();

	/*void setBreed(std::string newBreed);
	void setName(std::string newName);
	void setAge(int newAge);
	void setPhoto(std::string newPhoto);*/

	bool operator==(Pet pet);

	void show();

	std::string toString();
	std::string writeDog();

	friend std::istream & operator >> (std::istream &in, Pet & p);
	friend std::ostream & operator << (std::ostream &out, Pet & p);
	



};
