#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;

public:
	UI(Controller& c) : ctrl{ c } {}
	static void printMenu();

	void addBuilding();
	void printBuilding();
	void sortBuildings();

	void getAllDemolished();
	void getAllRestored();

	void start();

};
