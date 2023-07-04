#include "main_menu.h"
#include "clock_prompt.h"
#include "ui_main_menu.h"
#include "credits.h"
#include "PageSwitcher.h"
#include "walkthrough_page1.h"
#include "walkthrough_page2.h"

#include <QtWidgets>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QPainter>
#include <QFont>
#include <QRectF>
#include <QDebug>
#include <QGraphicsTextItem>

main_menu::main_menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::main_menu)
{
    ui->setupUi(this);
}

main_menu::~main_menu()
{
    delete ui;
    delete scene;
}

void main_menu::on_pushButton_clicked()
{
    scene = new myScene();
    scene->setSceneRect(-300, -300, 600, 600);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    //QGraphicsTextItem clock_prompt=new QGraphicsTextItem(" TIME: 00:00 ");
    clock_prompt* clock_object=new clock_prompt();
    clock_object->setPos(250,200);
    scene->addItem(clock_object);

    game_scene *view = new game_scene(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    view->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Starship Trek"));
    view->resize(1000, 800);
    view->show();

    qDebug("view show complete");

    timer = new QTimer();
    timerTwo = new QTimer();
    QObject::connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    QObject::connect(timerTwo, &QTimer::timeout, scene, &myScene::Stop);
    timer->start(1000 / 33);
    timerTwo->start(1000);

    qDebug("timer complete");
}

void main_menu::on_pushButton_2_clicked()
{
    Walkthrough_page1* wp1=new Walkthrough_page1;
    Walkthrough_page2* wp2=new Walkthrough_page2;
    PageSwitcher* pageSwitcher=new PageSwitcher;
    pageSwitcher->addPage(wp1);
    pageSwitcher->addPage(wp2);
    pageSwitcher->show();
}



void main_menu::on_pushButton_3_clicked()
{
    Credits* cre=new Credits;
    cre->show();
}


