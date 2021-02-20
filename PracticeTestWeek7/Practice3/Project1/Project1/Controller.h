#pragma once
#include "Repository.h"
#include "Gene.h"

class Controller 
{
private:
	Repository repo;

public:
	Controller(Repository r): repo { std::move(r)}{}

	Repository getRepo() const { return repo; }

	void addGeneToRepo(const std::string& name, const std::string& organism, const std::string& sequence);


};
