#include "HTMLRepository.h"
#include <vector>
#include <fstream>
#include <string>

HTMLRepository::HTMLRepository()
{
}

void HTMLRepository::writeAdoption()
{
	std::ofstream fout("AdoptionList.html");
	fout << "<!DOCTYPE html>\n";
	fout << "<html><head><title>" << "Adoption";
	fout << "</title></head>\n";
	fout << "<body><table border=\"1\">";
	fout << "<tr>\n";
	fout << "<td>Name</td>\n";
	fout << "<td>Breed</td>\n";
	fout << "<td>Age</td>\n";
	fout << "<td>Photograph</td>\n";
	fout << "</tr>\n";
	std::vector<Pet> adoptionList = this->getAdopted();
	for (auto it : adoptionList)
	{
		fout << "<tr>\n";
		fout << "<td>" << it.getBreed() << "</td>\n";
		fout << "<td>" << it.getName() << "</td>\n";
		fout << "<td>" << it.getAge() << "</td>\n";
		fout << "<td><a href = \"" << it.getPhoto() << "\">Photo</a></td>\n";
		fout << "</tr>\n";
	}
	fout << "</table></body></html>";
	fout.close();
}
void HTMLRepository::showAdoptionList()
{
	LPCTSTR file = "AdoptionList.html";
	ShellExecute(NULL, "open", file, NULL, NULL, SW_SHOWNORMAL);
}


HTMLRepository::~HTMLRepository()
{
}
