#pragma once
#include "Pet.h"
#include "Repository.h"

class Action 
{
public:
	Action() {}
	virtual void redo() = 0;
	virtual void undo() = 0;
};


class AddAction : public Action
{
public:
	AddAction(Repository* r, Pet pet) :Action(), repo(r), p(pet) {};
	Repository* repo;
	Pet p;

	void undo() override
	{
		repo->deletePet(p.getName());
	}
	void redo() override 
	{
		repo->addPet(p.getBreed(), p.getName(), p.getAge(), p.getPhoto());
	}
};


class RemoveAction : public Action
{
public:
	RemoveAction(Repository* r, Pet pet) : Action(), repo(r), p(pet) {};
	Repository* repo;
	Pet p;

	void undo() override
	{
		repo->addPet(p.getBreed(), p.getName(), p.getAge(), p.getPhoto());
	}
	void redo() override
	{
		repo->deletePet(p.getName());
	}
};

class UpdateAction : public Action
{
public:
	UpdateAction(Repository* r, Pet old, Pet newPet) :Action(), repo(r), old(old), newPet(newPet) {};
	Repository* repo;
	Pet old;
	Pet newPet;

	void undo() override
	{
		repo->updatePet(newPet.getBreed(), newPet.getName(), newPet.getAge(), newPet.getPhoto());
	}
	void redo() override 
	{
		repo->updatePet(old.getBreed(), old.getName(), old.getAge(), old.getPhoto());
	}
};