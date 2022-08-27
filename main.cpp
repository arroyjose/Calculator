#include "CalculatorMain.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalculatorMain w;
    w.show();
    return a.exec();
}
