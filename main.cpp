#include <QApplication>
#include <QtWidgets>

#include "starship.h"
#include "starship.cpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Starship w;
    w.show();
    return a.exec();
}
