#pragma once
#include "DynamicArray.h"
#include "Task.h"

class Repository
{
private:
	DynamicArray Tasks;

public:
	Repository() = default;

	void addTask(const Task& t);

	DynamicArray getTasks() const 
	{
		return Tasks;
	}

};