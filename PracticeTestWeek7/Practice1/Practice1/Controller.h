#pragma once
#include "DynamicArray.h"
#include "Project.h"
#include "Repository.h"

class Controller
{
private:

	Repository repo;

public:

	Controller(Repository r) : repo{ std::move(r) } {}
	Repository getRepo()  const { return repo; }

	//function that adds a new player to the existing ones
	void addEhfToRepo(std::string &name, std::string &nationality, std::string &team, int &goals);





};
