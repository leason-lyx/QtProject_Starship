#include "main_menu.h"
#include "ui_main_menu.h"

#include <QtWidgets>
#include <QStyle>
#include <QDebug>

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
    scene = new QGraphicsScene();
    scene->setSceneRect(-300, -300, 600, 600);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    ship = new Starship();
    ship->setPos(QPointF(0,0));
    scene->addItem(ship);

    view = new game_scene(scene);
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

//    QGraphicsScene scene;
//    scene.setSceneRect(-300, -300, 600, 600);
//    //! [1] //! [2]
//    scene.setItemIndexMethod(QGraphicsScene::NoIndex);
//    //! [2]
//    //! [3]
//    Starship ship;
//    ship.setPos(QPointF(0,0));
//    scene.addItem(&ship);
//    //! [4]
//    game_scene view(&scene);
//    view.setRenderHint(QPainter::Antialiasing);
//    //! [4] //! [5]
//    view.setCacheMode(QGraphicsView::CacheBackground);
//    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
//    view.setDragMode(QGraphicsView::ScrollHandDrag);
//    //! [5] //! [6]
//    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Starship Trek"));
//    view.resize(1000, 800);
//    view.show();
//    qDebug("view show complete");
//    QTimer timer;
//    QObject::connect(&timer, &QTimer::timeout, &scene, &QGraphicsScene::advance);
//    timer.start(1000 / 33);
//    qDebug("timer complete");
}

