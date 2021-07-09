#include "DiceRoll.h"
#include <QtWidgets/qboxlayout.h>
#include <qpixmap.h>
#include <time.h>

void DiceRoll::initGui() {
	QVBoxLayout* ly = new QVBoxLayout;
	ly->addWidget(dice);
	ly->addWidget(diceFace);
	ly->addWidget(btnRoll);
	ly->addWidget(num);
	setLayout(ly);
}
void DiceRoll::delay() {
	QTime waitTime = QTime::currentTime().addSecs(1);
	while (QTime::currentTime() < waitTime) {
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
	}
}

void DiceRoll::connectSignals() {
	QObject::connect(btnRoll, &QPushButton::clicked, this, [=]() {
		diceFace->hide();
		dice->show();
		gif->start();
		delay();
		dice->hide();

		srand(time(NULL));
		auto nr = rand() % 6 + 1;
		num->setText(QString::number(nr));
		switch (nr)
		{
		case 1:
			diceFace->setPixmap(QPixmap("resources/face1.png"));
			diceFace->show();
			break;
		case 2:
			diceFace->setPixmap(QPixmap("resources/face2.png"));
			diceFace->show();
			break;
		case 3:
			diceFace->setPixmap(QPixmap("resources/face3.png"));
			diceFace->show();
			break;
		case 4:
			diceFace->setPixmap(QPixmap("resources/face4.png"));
			diceFace->show();
			break;
		case 5:
			diceFace->setPixmap(QPixmap("resources/face5.png"));
			diceFace->show();
			break;
		case 6:
			diceFace->setPixmap(QPixmap("resources/face6.png"));
			diceFace->show();
			break;
		}
		});
}

void DiceRoll::setInitialState() {
	num->setDisabled(true);
	dice->setMovie(gif);
	dice->hide();
	diceFace->hide();
	diceFace->setStyleSheet("QLabel{display: block; margin: auto;}");
}