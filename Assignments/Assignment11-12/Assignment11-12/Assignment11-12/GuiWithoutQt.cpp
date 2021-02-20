#include "GuiWithoutQT.h"
#include "Validator.h"
#include <sstream>
#include <string>
#include <Windows.h>
#include <QLinearGradient>
#include <QPalette>
#include <QBrush>
#include <QApplication>

using namespace std;

GuiLab11::~GuiLab11()
{
}

GuiLab11::GuiLab11(QWidget* parent) : QWidget{ parent }
{
	this->init();
	
}

void GuiLab11::addController(Controller* c)
{
	this->ctrl = c;

	this->petVector = this->ctrl->getAll();
	this->populate();
}

void GuiLab11::init()
{
	QHBoxLayout* layout = new QHBoxLayout{};

	QWidget* leftW = new QWidget{};
	QVBoxLayout* leftSide = new QVBoxLayout{ leftW };

	this->pets = new QListWidget{};
	this->pets->setSelectionMode(QAbstractItemView::SingleSelection);

	QWidget* petDataWidget = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ petDataWidget };

	this->breedInput = new QLineEdit{};
	this->nameInput = new QLineEdit{};
	this->ageInput = new QLineEdit{};
	this->photoInput = new QLineEdit{};

	formLayout->addRow("&Breed: ", breedInput);
	formLayout->addRow("&Name: ", nameInput);
	formLayout->addRow("&Age: ", ageInput);
	formLayout->addRow("&Photo: ", photoInput);

	QWidget* buttonsWidget = new QWidget{};
	QGridLayout* gridLayout = new QGridLayout{ buttonsWidget };

	this->addButton = new QPushButton("Add a pet", this);
	this->deleteButton = new QPushButton("Delete a pet", this);
	this->updateButton = new QPushButton("Update a pet", this);

	gridLayout->addWidget(addButton, 0, 0);
	gridLayout->addWidget(deleteButton, 0, 1);
	gridLayout->addWidget(updateButton, 0, 2);


	layout->addWidget(leftW);
	layout->addWidget(pets);
	layout->addWidget(petDataWidget);
	layout->addWidget(buttonsWidget);
	this->setLayout(layout);

	
	leftSide->addWidget(new QLabel{ "Pets" });
	leftSide->addWidget(pets);
	leftSide->addWidget(petDataWidget);
	leftSide->addWidget(buttonsWidget);


	QWidget* middleW = new QWidget{};
	QVBoxLayout* vLayoutMiddle = new QVBoxLayout{ middleW };
	this->moveOneButton = new QPushButton(">", middleW);

	vLayoutMiddle->addWidget(moveOneButton);
	middleW->setLayout(vLayoutMiddle);

	vLayoutMiddle->addWidget(moveOneButton);


	QWidget* rightW = new QWidget{};
	QVBoxLayout* rightSide = new QVBoxLayout{ rightW };


	adoptionList = new QListWidget{};


	QWidget* addoptionListButtonWidget = new QWidget{};
	QHBoxLayout* addoptionListButtonLayout = new QHBoxLayout{ addoptionListButtonWidget };
	this->showButton = new QPushButton{ "Show" };
	addoptionListButtonLayout->addWidget(this->showButton);
	this->nextButton = new QPushButton{ "Next" };
	addoptionListButtonLayout->addWidget(this->nextButton);

	rightSide->addWidget(new QLabel{ "Adoption list" });
	rightSide->addWidget(adoptionList);
	rightSide->addWidget(addoptionListButtonWidget);

	layout->addWidget(leftW);
	layout->addWidget(middleW);
	layout->addWidget(rightW);

	QLinearGradient linearGrad(0, 0, 450, 450);
	linearGrad.setColorAt(0, QColor(0, 0, 0));
	linearGrad.setColorAt(1, QColor(255, 255, 255));
	QBrush brush(linearGrad);

	QPalette qp= qApp->palette();
	qp.setBrush(QPalette::Base, brush);
	qp.setBrush(QPalette::Highlight, linearGrad);
	qp.setBrush(QPalette::HighlightedText, Qt::red);
	qp.setBrush(QPalette::Text, Qt::white);
	this->pets->setPalette(qp);

	this->connectSignalsSlots();
		
}

void GuiLab11::addPet()
{
	string breed = breedInput->text().toStdString();
	string name = nameInput->text().toStdString();
	int age = stoi(ageInput->text().toStdString());
	string photo = photoInput->text().toStdString();

	string petString = breed + ", " + name + ", " + to_string(age) + ", " + ", " + photo;
	stringstream stream{ petString };

	try
	{
		ctrl->addPetToRepo(breed, name, age, photo);

		petVector = this->ctrl->getAll();
		this->populate();
	}
	catch (Validator& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString("Invalid input"));
	}
	catch (RepositoryException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString("Pet already exist"));
	}

}

void GuiLab11::deletePet()
{
	string name = nameInput->text().toStdString();
	try
	{
		ctrl->removePetFromRepo(name);

		petVector = this->ctrl->getAll();
		this->populate();
	}
	catch (RepositoryException& e)
	{

		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString("Pet does not exist"+name));
	}
}

void GuiLab11::updatePet()
{
	string breed = breedInput->text().toStdString();
	string name = nameInput->text().toStdString();
	int age = stoi(ageInput->text().toStdString());
	string photo = photoInput->text().toStdString();

	string petString = breed + ", " + name + ", " + to_string(age) + ", " + ", " + photo;
	stringstream stream{ petString };

	try 
	{
		ctrl->updatePetFromRepo(breed, name, age, photo);
		petVector = this->ctrl->getAll();

		this->populate();
	}
	catch (RepositoryException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString("Invalid input"));
	}

}


void GuiLab11::moveToAdoptionList()
{
	QListWidgetItem* it = new QListWidgetItem{ *(this->pets->currentItem()) };
	this->adoptionList->addItem(it);
}

void GuiLab11::moveNext()
{
	if (this->adoptionList->count() == 0)
	{
		return;
	}
	int rowIndex = this->adoptionList->currentRow();
	this->adoptionList->setCurrentRow(rowIndex + 1);
}

void GuiLab11::undo()
{

}

std::vector<std::string> GuiLab11::tokenize(const std::string & str, char delimiter)
{
	vector <string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}


void GuiLab11::showLink()
{
	QListWidgetItem* it = this->adoptionList->currentItem();
	std::string linie = it->text().toStdString();
	std::vector<std::string> tokens = tokenize(linie, ',');
	
	ShellExecuteA(NULL, NULL, "chrome.exe", tokens[3].c_str(), NULL, SW_SHOWMAXIMIZED);
}


void GuiLab11::connectSignalsSlots()
{
	QObject:connect(pets, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged()));

	QObject::connect(this->addButton, SIGNAL(clicked()), this, SLOT(addPet()));
	QObject::connect(this->deleteButton, SIGNAL(clicked()), this, SLOT(deletePet()));
	QObject::connect(this->updateButton, SIGNAL(clicked()), this, SLOT(updatePet()));
	QObject::connect(this->moveOneButton, SIGNAL(clicked()), this, SLOT(moveToAdoptionList()));
	QObject::connect(this->nextButton, SIGNAL(clicked()), this, SLOT(moveNext()));
	QObject::connect(this->showButton, SIGNAL(clicked()), this, SLOT(showLink()));
	QObject::connect(this->undoButton, SIGNAL(clicked()), this, SLOT(undo()));
	QObject::connect(this->redoButton, SIGNAL(clicked()), this, SLOT(redo()));

}

void GuiLab11::populate()
{
	if (pets->count() != 0)
		pets->clear();

	for (auto it : petVector)
	{
		QString listItem = QString::fromStdString(it.toString());
		QListWidgetItem *listItemWidget = new QListWidgetItem(listItem);
		this->pets->addItem(listItemWidget);
	}
	if (petVector.size() > 0)
		pets->setCurrentRow(0);
}

void GuiLab11::populateWL()
{
	if (adoptionList->count() != 0)
		adoptionList->clear();

	for (auto it : (this->ctrl->getAllAdopted()))
	{
		QString itemList = QString::fromStdString(it.getBreed() + ", " + it.getName() + ", " + to_string(it.getAge()) + ", " + it.getPhoto()+".");
		this->adoptionList->addItem(itemList);
	}
}
