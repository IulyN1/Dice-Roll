#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlineedit.h>
#include <qmovie.h>
#include <qlabel.h>

class DiceRoll: public QWidget
{
private:
	QPushButton* btnRoll = new QPushButton{"Roll"};
	QLineEdit* num = new QLineEdit;
	QMovie* gif = new QMovie{"resources/dice.gif"};
	QLabel* dice = new QLabel;
	QLabel* diceFace = new QLabel;

	// Function that delays the execution of the app with 1 second
	void delay();

	// Function that initializes the GUI components
	void initGui();

	// Function that connects the signals of the components
	void connectSignals();

	// Function that sets the initial state of the application
	void setInitialState();
public:
	DiceRoll() {
		initGui();
		connectSignals();
		setInitialState();
	}
};

