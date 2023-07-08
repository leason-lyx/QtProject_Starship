#include <QApplication>
#include <QtWidgets>
#include <QStyle>
#include <QUrl>

#include "main_menu.h"
#include "scorewindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    ScoreWindow w;
//    w.resize(800, 600);
//    w.show();

//    w.animateScore(100); // 将最终得分设置为100，分数会滚动到这个值
    main_menu menu;
    menu.show();
    return a.exec();
}
