#include <QApplication>
#include <QtWidgets>
#include <QStyle>

#include "main_menu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    main_menu menu;
    menu.show();
    return a.exec();
}
