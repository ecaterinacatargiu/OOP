#include "DynamicArray.h"
#include "Task.h"
#include "Repository.h"
#include "Controller.h"
#include "UI.h"

int main()
{
	Repository repository{};

	Task t1{ "Read", 60, 1 };
	Task t2{ "Gym", 120, 2 };
	Task t3{ "Going out", 100, 3 };
	Task t4{ "Studying", 200, 1 };
	Task t5{ "Sleeping", 65, 2 };

	repository.addTask(t1);
	repository.addTask(t2);
	repository.addTask(t3);
	repository.addTask(t4);
	repository.addTask(t5);

	Controller controller{ repository };
	UI ui{ controller };

	ui.Start();

	return 0;
}