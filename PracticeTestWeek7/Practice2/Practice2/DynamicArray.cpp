#include "DynamicArray.h"

DynamicArray::DynamicArray(int cap)
{
	this->size = 0;
	this->capacity = cap;
	this->elems = new TElem[this->capacity];
}

DynamicArray::DynamicArray(const DynamicArray & v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new TElem[this->capacity];

	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

DynamicArray & DynamicArray::operator=(const DynamicArray & v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	
	delete[] this->elems;
	this->elems = new TElem[this->capacity];

	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

	return *this;
}

int DynamicArray::getSize() const
{
	return this->size;
}

int DynamicArray::getCapacity() const
{
	return this->capacity;
}

TElem * DynamicArray::getAll() const
{
	return this->elems;
}

void DynamicArray::add(const TElem & e)
{
	if (this->size == this->capacity)
		this->resize();

	this->elems[this->size] = e;
	this->size++;
}

DynamicArray::~DynamicArray()
{
	delete[] this->elems;
}

void DynamicArray::resize(double mulfac)
{
	this->capacity *= static_cast<int>(mulfac);

	TElem* elms = new TElem[this->capacity];
	for (int i = 0; i < this->size; i++)
		elms[i] = this->elems[i];

	delete[] this->elems;
	this->elems = elms;
}
