#pragma once
#include "Gene.h"
#include <stdlib.h>

typedef Gene TElem;

class DynamicArray
{
private:
	int size, capacity;
	TElem* elems;

public:
	DynamicArray(int cap = 10);
	DynamicArray(const DynamicArray& v);
	DynamicArray& operator=(const DynamicArray& v);

	int getSize() const;
	int getCapacity() const;
	TElem* getAll() const;

	void add(const TElem& e);

	~DynamicArray();

private:
	void resize(double mulfac = 2);
};
