#pragma once
#include "Controller.h"
#include "Task.h"

class UI 
{
private:
	Controller ctrl;

public:
	UI(const Controller& c) : ctrl(c) {}

	void Start();

private:

	static void printMenu();

	void displayTasks();
	void addTaskToRepo();
	void sortTasks();
	void getDurationByPriority();
};