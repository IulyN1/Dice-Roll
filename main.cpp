#include "DiceRoll.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DiceRoll* w = new DiceRoll;
    w->show();
    return a.exec();
}
