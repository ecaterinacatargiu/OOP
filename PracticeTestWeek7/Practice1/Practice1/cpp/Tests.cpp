#include "Tests.h"
#include "Repository.h"
#include "Controller.h"
#include "UI.h"
#include <stdlib.h>
#include <cassert>

void Tests::testRepo()
{
	Repository repo{};

	std::string n1{ "Cati" };
	std::string c1{ "ROU" };
	std::string tt{ "GH" };
	int s { 40};

	EHF ehf{ n1,c1,tt,s};
	repo.addEhf(ehf);
}

void Tests::testCtrl()
{
	Repository repo;
	Controller ctrl{ repo };

	std::string n1{ "Cati" };
	std::string c1{ "ROU" };
	std::string tt{ "GH" };
	int s{ 40 };

	EHF ehf{ n1,c1,tt,s };
	repo.addEhf(ehf);

	ctrl.addEhfToRepo(n1, c1, tt, s);
}

void Tests::testGoals()
{
	Repository repo;
	Controller ctrl{ repo };
	UI ui{ ctrl };
	
	//ui.getGoals();
}

void Tests::runTests()
{
	this->testRepo();
	this->testCtrl();
}
