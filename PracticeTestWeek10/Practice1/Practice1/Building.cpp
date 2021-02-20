#include "Building.h"
#include <string>
#include <vector>


Building::~Building()
{
}

int Building::getYear()
{
	return this->year;
}

std::string Building::getAdress()
{
	return this->adress;
}

std::string Building::toString()
{
	std::string buildingString = "Address: " + this->getAdress() + "Year: " + std::to_string(this->getYear());
	return buildingString;
}


Block::Block(const int totalApartments, const int occupiedApartments, std::string adress, int year) : totalApartments{ totalApartments }, occupiedApartments{ occupiedApartments }
{ 
	this->adress = adress; 
	this->year = year; 
}

int Block::getTotalApartments()
{
	return this->totalApartments;
}

int Block::getOccupiedApartments()
{
	return this->occupiedApartments;
}

bool Block::mustBeRestored()
{
	float ocAp = float(this->getOccupiedApartments());
	float percentage = float(0.8*(this->getTotalApartments()));
	if(this->getYear()>40 && ocAp>percentage)
		return true;
	return false;
}

bool Block::canBeDemolished()
{
	if(float(this->getOccupiedApartments())<float(0.05*(this->getTotalApartments())))
		return true;
	return false;
}

std::string Block::toString()
{
	std::string BlockString = "Address: " + this->getAdress() + "," + "Year of construction: " + std::to_string(this->getYear()) + "," + "Total appartments: " + std::to_string(this->getTotalApartments()) + "," + "Occupied appartments: " + std::to_string(this->getOccupiedApartments());
	return BlockString;
}


House::House(std::string type, bool isHistorical, std::string adress, int year): typeH{typeH}, isHistorical{isHistorical}
{ 
	this->adress = adress; 
	this->year = year; 
}


std::string House::getTypeH()
{
	return this->typeH;
}

bool House::getHist()
{
	return this->isHistorical;
}

bool House::mustBeRestored()
{
	if (this->year > 100)
		return true;
	return false;
}

bool House::canBeDemolished()
{
	if (!this->isHistorical)
		return true;
	return false;
}

std::string House::toString()
{
	std::string HouseString = "Address: "+ this->getAdress() +","+ "Year of construction: "+ std::to_string(this->getYear()) + "," +"Type: " + this->getTypeH() + "," + "Is historical: " + std::to_string(this->getHist());
	return HouseString;
}
