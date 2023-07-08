#include <QApplication>
#include <QtWidgets>
#include <QStyle>
#include <QUrl>
#include <QSoundEffect>

#include "main_menu.h"
//#include "scorewindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    main_menu menu;
    menu.show();
    return a.exec();
}
