#include "CsvRepository.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

CSVRepository::CSVRepository()
{

}

void CSVRepository::writeAdoption()
{
	std::ofstream fout("AdoptionList.csv");
	std::vector<Pet> adoptionList = this->getAdopted();
	for (auto it : adoptionList)
	{
		fout << it.getBreed() << "," << it.getName() << "," << it.getAge() << "," << it.getPhoto() << "\n";
	}
}
void CSVRepository::showAdoptionList()
{
	LPCTSTR file = "AdoptionList.csv";
	ShellExecute(NULL, "open", file, NULL, NULL, SW_SHOWNORMAL);
}


CSVRepository::~CSVRepository()
{
}
