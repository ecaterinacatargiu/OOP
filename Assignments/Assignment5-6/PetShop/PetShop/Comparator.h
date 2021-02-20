#pragma once
#include "Pet.h"
template <typename Elems>
class Comparator
{
public:
	virtual bool relation(Elems& el1, Elems& el2) = 0;
	virtual ~Comparator() {};
};

class CompareDescendingByAge :public Comparator<Pet>
{
public:
	bool relation(Pet& p1, Pet& p2) override { return p1.getAge() > p2.getAge(); }

};

class CompareAscendingByBreed :public Comparator<Pet>
{
public:
	bool relation(Pet& p1, Pet& p2) override { return p1.getBreed() < p2.getBreed(); }
};
