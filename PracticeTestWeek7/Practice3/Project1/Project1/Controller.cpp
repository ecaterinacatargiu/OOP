#include "Controller.h"

void Controller::addGeneToRepo(const std::string & name, const std::string & organism, const std::string & sequence)
{
	Gene gene{ name, organism, sequence };

	this->repo.addGene(gene);
}
