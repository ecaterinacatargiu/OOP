#pragma once
#include "Repository.h"

class CSVRepository : public Repository
{
public:
	CSVRepository();
	void writeAdoption() override;
	void showAdoptionList() override;
	~CSVRepository();
};
