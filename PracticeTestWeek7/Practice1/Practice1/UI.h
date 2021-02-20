#pragma once
#include "DynamicArray.h"
#include "Controller.h"
#include "Project.h"

class UI
{
private:
	Controller ctrl;

public:
	UI(const Controller& c) : ctrl(c) {}

	void startApp();

private:

	static void printMenu();

	void addEhfToRepo();
	void displayPlayers();
	void sortPlayersByGoals();

	//function that computes the total goals of the player from a given country
	void getGoals();

};
