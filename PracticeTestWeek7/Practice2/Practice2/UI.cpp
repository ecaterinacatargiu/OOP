#include "UI.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

void UI::Start()
{
	while(true)
	{
		UI::printMenu();
		int option{ 0 };
		cout << endl;
		cout << "Please choose one of the following option: ";
		cin >> option;
		cin.ignore();
		cout << endl;
		if (option == 0)
			break;
		else if (option == 1)
			this->displayTasks();
		else if (option == 2)
			this->addTaskToRepo();
		else if (option == 3)
			this->sortTasks();
		else if (option == 4)
			this->getDurationByPriority();
	}
	
}

void UI::printMenu()
{
	cout << endl;
	cout << "1 - See tasks." << endl;
	cout << "2 - Add a new task." << endl;
	cout << "3 - Sort tasks by priority. " << endl;
	cout << "4 - Total duration of the tasks with a given priority." << endl;
}

void UI::displayTasks()
{
	DynamicArray v = this->ctrl.getRepo().getTasks();
	Task* tasks = v.getAll();

	for (int i = 0; i < v.getSize(); i++)
	{
		Task t = tasks[i];
		cout << t.getDescription() << ", " << t.getDuration() << "minutes, " << t.getPriority() << "." << endl;
	}
}

void UI::addTaskToRepo()
{
	cout << "Enter the description: ";
	std::string description;
	getline(cin, description);
	int duration = 0;
	cout << "Enter the duration: ";
	cin >> duration;
	cin.ignore();
	int priority = 0;
	cout << "Enter the priority: ";
	cin >> priority;
	cin.ignore();

	this->ctrl.addProjectToRepo(description, duration, priority);
}

void UI::sortTasks()
{
	DynamicArray da = this->ctrl.getRepo().getTasks();
	Task* task = da.getAll();

	for (int i = 0; i < da.getSize() - 1; i++)
		for (int j = i; j < da.getSize(); j++)
			if (task[i].getDuration() < task[j].getDuration())
			{
				swap(task[i], task[j]);
			}

	for (int i = 0; i <da.getSize(); i++)
	{
		Task t = task[i];
		cout << t.getDescription() << ", " << t.getDuration() << " minutes," << t.getPriority() << "." << endl;

	}
}

void UI::getDurationByPriority()
{
	int duration = 0;
	DynamicArray v = ctrl.getRepo().getTasks();
	Task* tasks = v.getAll();

	int priority = 0;
	cout << "Enter the priority: ";
	cin >> priority;
	cin.ignore();

	for (int i = 0; i < v.getSize(); i++)
		if (tasks[i].getPriority() < priority)
			duration += tasks[i].getDuration();

	cout << duration << " minutes" << endl;

}

