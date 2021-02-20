#pragma once
#include <string>


class EHF
{
private:

	std::string name;
	std::string nationality;
	std::string team;
	int goals;

public:

	EHF();
	EHF(const std::string & name, const std::string & n, const std::string & t, const int & g);
	~EHF();

	std::string getName();
	std::string getNationality();
	std::string getTeam();
	int getGoals();

	void setName(std::string newName);
	void setNationality(std::string newNationality);
	void setTeam(std::string newTeam);
	void setGoals(int newGoals);

	std::string toString();

	int operator==(EHF ehf);
	int operator<(EHF ehf);

};
