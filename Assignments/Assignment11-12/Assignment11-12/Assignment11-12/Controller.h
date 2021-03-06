#pragma once
#include "Repository.h"
#include "Comparator.h"
#include <stack>
#include "UndoRedo.h"


class Controller
{
private:

	Repository* r;

public:
	Controller(Repository *repo) : r{ repo } {}

	int addPetToRepo(const std::string name, const std::string breed, const int age, const std::string photo);
	int removePetFromRepo(const std::string name);
	int updatePetFromRepo(const std::string breed, const std::string name, const int age, const std::string photo);

	int addPetToAdoptionList(Pet p);

	std::vector<Pet> getAll();
	std::vector<Pet> getAllAdopted();

	int getSize();
	int getSizeAdopted();

	std::vector<Pet> filterPets(const std::string breed, const int age);

	std::vector<Pet> sortPets(Comparator<Pet>* comp, std::vector<Pet> list);
	std::vector<Pet> compareAge();
	std::vector<Pet> compareBreed();

	void showAdoptionList();

	~Controller();
};

class UndoFct
{
private:
	std::vector<std::unique_ptr<Action>> stack;
	//std::stack<std::unique_ptr<UndoAction>> undoStack;
	//std::stack<std::unique_ptr<RedoAction>> redoStack;

public:
	UndoFct();
	~UndoFct();

	void addOperation(std::unique_ptr<Action>ptr);
	void doUndo();
	void doRedo();
};
