#include "Controller.h"

void Controller::addEhfToRepo(std::string &name, std::string &nationality, std::string &team, int &goals)
{
	EHF ehf{ name, nationality, team, goals };

	this->repo.addEhf(ehf);

}
