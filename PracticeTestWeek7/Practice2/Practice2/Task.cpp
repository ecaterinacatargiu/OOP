#include "Task.h"

Task::Task() : description{ "" }, duration(0), priority(0)
{
}

Task::Task(const std::string & description, const int & duration, const int & priority) :
	description{ description }, duration{ duration }, priority{ priority }
{

}

std::string Task::getDescription()
{
	return this->description;
}

int Task::getDuration()
{
	return this->duration;
}

int Task::getPriority()
{
	return this->priority;
}

void Task::setDescription(std::string newDescription)
{
	this->description = newDescription;
}

void Task::setDuration(int newDuration)
{
	this->duration = newDuration;
}

void Task::setPriority(int newPriority)
{
	this->priority = newPriority;
}

std::string Task::toString()
{
	std::string myString(this->duration + "\n");
	myString.append(this->duration + "\n");
	myString.append(this->priority + "\n");

	return myString;
}

int Task::operator==(Task task)
{
	return this->getDescription().compare(task.getDescription()) == 0;
}

int Task::operator<(Task task)
{
	return this->getDuration() < task.getDuration() || this->getPriority() < task.getPriority();
}
