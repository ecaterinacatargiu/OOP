#pragma once
#include <string>

class Building 
{
protected:
	std::string adress;
	int year;

public:
	Building() {}
	virtual ~Building();

	int getYear();
	std::string getAdress();

	virtual bool mustBeRestored() = 0;
	virtual bool canBeDemolished() = 0;
	virtual std::string toString() = 0;
	
};

class Block: public Building
{
private:
	int totalApartments;
	int occupiedApartments;

public:
	Block(int totalApartments, int occupiedApartments, std::string adress, int year);

	int getTotalApartments();
	int getOccupiedApartments();

	bool mustBeRestored() override;
	bool canBeDemolished() override;
	std::string toString() override;

};

class House : public Building 
{
private:
	std::string typeH;
	bool isHistorical;

public:
	House(std::string type, bool isHistorocal, std::string adress, int year);

	std::string getTypeH();
	bool getHist();

	bool mustBeRestored() override;
	bool canBeDemolished()  override;
	std::string toString() override;

};
