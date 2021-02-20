#pragma once
#include "Pet.h"
#include <iostream>

class RepositoryException : public std::exception
{
private:
	std::string message;

public:
	RepositoryException(std::string msg);
	const char* what() const noexcept override;
};

class ControllerException : public std::exception
{
private:
	std::string message;

public:
	ControllerException(std::string msg);
	const char* what() const noexcept override;
};

class PetException : public std::exception
{
private:
	std::string message;

public:
	PetException(std::string msg);
	const char* what() const noexcept override;
};

class Validator
{
public:
	Validator(Pet p);
	static bool isStrEmpty(const std::string& s);
	static std::string checkString(const std::string& s);

	~Validator();

};
