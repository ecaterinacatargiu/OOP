#pragma once
#include <stdlib.h>
#include <string>

class Task 
{
private:
	std::string description;
	int duration;
	int priority;

public:
	Task();
	Task(const std::string& description, const int& duration, const int& priority);

	std::string getDescription();
	int getDuration();
	int getPriority();

	void setDescription(std::string newDescription);
	void setDuration(int newDuration);
	void setPriority(int newPriority);

	std::string toString();

	int operator==(Task task);
	int operator<(Task task);

};