#include "Repository.h"
#include "DynamicArray.h"
#include "Task.h"

void Repository::addTask(const Task & newTask)
{
	this->Tasks.add(newTask);
}
