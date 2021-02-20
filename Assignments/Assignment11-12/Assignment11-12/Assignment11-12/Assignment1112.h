#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Assignment1112.h"
#include "GuiWithoutQT.h"
class Assignment1112 : public QMainWindow
{
	Q_OBJECT

public:
	Assignment1112(QWidget *parent = Q_NULLPTR);

private:
	Ui::Assignment1112Class ui;
};
