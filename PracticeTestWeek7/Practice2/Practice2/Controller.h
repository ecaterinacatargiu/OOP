#pragma once
#include "Repository.h"
#include "Task.h"

class Controller
{
private:
	Repository repo;

public:

	Controller(Repository r) : repo{ std::move(r) } {}

	Repository getRepo() const { return repo; }

	void addProjectToRepo(const std::string& description, int duration, int priority);

};
