#pragma once
#include "Controller.h"

class UI 
{
private:
	Controller ctrl;

public:

	UI(Controller &ctrl): ctrl { ctrl } {}
	void start();
	~UI();

private:
	
	static void printMenu();
	static void printAdminMenu();
	static void printUserMenu();

	void startUserMode();
	void startAdministratorMode();

	void addPettoRepo();
	void removePetFromRepo();
	void updatePetFromRepo();
	void displayPets();

	void listPets();
	void filteredAdoption();

	void listAdoption();
	void displayAdoption();

};