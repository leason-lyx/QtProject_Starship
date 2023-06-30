#include "main_menu.h"
#include "clock_prompt.h"
#include "ui_main_menu.h"

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
    clock_object->setPos(500,450);
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
    QObject::connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    timer->start(1000 / 33);

    qDebug("timer complete");
}

