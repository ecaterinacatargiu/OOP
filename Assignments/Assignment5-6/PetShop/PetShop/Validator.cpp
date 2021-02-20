#include "Validator.h"


RepositoryException::RepositoryException(std::string msg) : message{ msg } 
{
}

const char * RepositoryException::what() const noexcept
{
	return this->message.c_str();
}

ControllerException::ControllerException(std::string msg) : message{ msg }
{
}

const char * ControllerException::what() const noexcept
{
	return this->message.c_str();
}

PetException::PetException(std::string msg) : message{ msg }
{
}

const char * PetException::what() const noexcept
{
	return this->message.c_str();
}

Validator::Validator(Pet p)
{
	std::string errors;
	errors = "";
	if (p.getBreed() == "")
		errors += "Breed is empty, type a breed.\n";
	if(p.getName()=="")
		errors += "Name is empty, type a name.\n";
	if (p.getAge() <= 0)
		errors += "Invalid age.\n";
	if(p.getPhoto() == "")
		errors += "Photo is empty, type a photo.\n";
	if (errors != "")
		throw PetException(errors);
}

Validator::~Validator()
{
}
