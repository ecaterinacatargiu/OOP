#pragma once
#include "DynamicArray.h"
#include "Project.h"

class Repository
{
private:
	DynamicArray EHFs;

public:

	Repository() = default;

	DynamicArray getEhf() const { return EHFs; }

	//function that add a new player to the existing ones
	void addEhf(const EHF& e);
};

