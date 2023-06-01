#include "mainwindow.h"
#include "gamewidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Starship Beta");
    w.setFixedHeight(768);
    w.setFixedWidth(1024);
    w.show();
    return a.exec();
}
