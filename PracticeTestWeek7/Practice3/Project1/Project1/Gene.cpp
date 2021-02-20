#include "Gene.h"

Gene::Gene(): name { "" }, organism { "" }, sequence { ""}
{
}

Gene::Gene(const std::string & name, const std::string & organism, const std::string & sequence):
	name { name }, organism { organism }, sequence { sequence}
{
}

std::string Gene::getName()
{
	return this->name;
}

std::string Gene::getOrganism()
{
	return this->organism;
}

std::string Gene::getSequence()
{
	return this->sequence;

}

void Gene::setName(std::string newName)
{
	this->name = newName;
}

void Gene::setOrganism(std::string newOrganism)
{
	this->organism = newOrganism;
}

void Gene::setSequence(std::string newSequence)
{
	this->sequence = newSequence;
}

std::string Gene::toString()
{
	std::string myString(this->name + "\n");
	myString.append(this->organism + "\n");
	myString.append(this->sequence + "\n");

	return myString;
}

int Gene::operator==(Gene gene)
{
	return this->getName().compare(gene.getName()) == 0 && this->getOrganism().compare(gene.getOrganism()) == 0 && this->getSequence().compare(gene.getSequence()) == 0;
}

int Gene::operator<(Gene gene)
{
	return this->getOrganism() < gene.getOrganism();
}
