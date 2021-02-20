#pragma once
#include "DynamicArray.h"
#include "Gene.h"

class Repository 
{
private:
	DynamicArray Genes;

public:
	Repository() = default;

	void addGene(const Gene& g);

	DynamicArray getGenes()  const { return Genes; }

};
