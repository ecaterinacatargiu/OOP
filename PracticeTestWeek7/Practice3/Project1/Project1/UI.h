#pragma once
#include "Controller.h"
#include "Gene.h"

class UI 
{
private:
	Controller ctrl;

public:
	UI(const Controller& c) : ctrl(c) {}

	void Start();

private:

	static void printMenu();

	void displayGenes();
	void addGenes();
	void sortGenesByOrganism();
	void getTheGenes();
};