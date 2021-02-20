#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qradiobutton.h>
#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/qbuttongroup.h>
#include <QLinearGradient>
#include <QtWidgets/QTableView>
#include <QPalette>

#include "Pet.h"
#include "Controller.h"

#include <vector>
#include <algorithm>

class GuiLab11 : public QWidget
{
	Q_OBJECT

public:

	GuiLab11(QWidget* parent = Q_NULLPTR);
	~GuiLab11();
	void addController(Controller*);
	void populate();
	void populateWL();
	

private:

	void init();

	Controller* ctrl;
	std::vector<Pet> petVector;

	QTableView *petView;
	//lists
	QListWidget *pets;
	QListWidget *adoptionList;

	//form
	QLineEdit* breedInput;
	QLineEdit* nameInput;
	QLineEdit* ageInput;
	QLineEdit* photoInput;


	//buttons
	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* updateButton;

	QPushButton* moveOneButton;
	QPushButton* moveAllButton;
	QPushButton* nextButton;
	QPushButton* showButton;

	QPushButton *undoButton;
	QPushButton *redoButton;

private slots:

	void addPet();
	void deletePet();
	void updatePet();
	void moveToAdoptionList();
	void moveNext();

	void undo();
	void redo();


	std::vector<std::string> tokenize(const std::string& str, char delimiter);
	void showLink();

	void connectSignalsSlots();


};
