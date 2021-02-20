#pragma once
#include "Project.h"
#include <string>

typedef EHF TElem;

class DynamicArray
{
private:
	int size, capacity;
	TElem* elems;

public:
	DynamicArray(int cap=10); //constructor
	DynamicArray(const DynamicArray& v); //copy constructor
	DynamicArray& operator=(const DynamicArray&v); //assignment operator


	int getSize() const;
	int getCapacity() const;
	TElem* getAll() const;

	void add(const TElem& e); // adds a new element to the current dynamic array

	~DynamicArray();

private:
	
	void resize(double mulfac = 2); // resizing the dynamic array

};

