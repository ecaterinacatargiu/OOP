#include "Controller.h"

void Controller::addProjectToRepo(const std::string & description, int duration, int priority)
{
	Task task{ description, duration, priority };

	this->repo.addTask(task);
}
