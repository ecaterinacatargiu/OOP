#include "Assignment1112.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include "Controller.h"
#include "Repository.h"
#include "CsvRepository.h"
#include "HTMLRepository.h"
#include <crtdbg.h>
#include <iostream>
#include "GuiWithoutQT.h"

using namespace std;


int main(int argc, char *argv[])
{
	/*int i;
	std::cout << "Which mode do you want to try? " << endl;
	cout << endl;
	std::cout << "1 - CSV file" << endl;
	std::cout << "2 - HTML file" << endl;
	cout << endl;
	std::cout << "Please enter your option: ";
	std::cin >> i;
	*/
	Repository *r = new CSVRepository;

	/*cout << endl;
	if (i == 1)
	{
		r = new CSVRepository();
	}
	else
	{
		r = new HTMLRepository();
	}*/
	r->readFile("pets.txt");

	QApplication a(argc, argv);
	Controller ctrl{r};


	GuiLab11 w;
	w.addController(&ctrl);
	w.show();
	return a.exec();
}
