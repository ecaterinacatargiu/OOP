#include <iostream>
#include "Controller.h"
#include "Repository.h"
#include "CsvRepository.h"
#include "HTMLRepository.h"
#include "UI.h"
#include <crtdbg.h>
#include <iostream>

using namespace std;

int main()
{
	{
		int i;
		std::cout << "Which mode do you want to try? " << endl;
		cout << endl;
		std::cout << "1 - CSV file" << endl;
		std::cout << "2 - HTML file"<<endl;
		cout << endl;
		std::cout << "Please enter your option: ";
		std::cin >> i;
		Repository *r;
		cout << endl;
		if (i == 1)
		{
			r = new CSVRepository();
		}
		else
		{
			r = new HTMLRepository();
		}
		r->readFile("pets.txt");
		Controller ctrl{ r };
		UI u{ ctrl };
		u.start();
		delete r;
	}
	//_CrtDumpMemoryLeaks();
	return 0;
}