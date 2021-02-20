#pragma once
#include "Controller.h"

class UI 
{
private:
	Controller ctrl;

public:
	UI(Controller& c) : ctrl{ c } {}

	static void printMenu();

	void addAppliance();
	void printAppliance();
	void sortAppliances();

	void putIntoFile();

	void start();

};