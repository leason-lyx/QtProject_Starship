#include <QApplication>
#include <QtWidgets>
#include <QStyle>

#include "starship.h"
#include "starship.cpp"
#include "game_scene.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene scene;
    scene.setSceneRect(-300, -300, 600, 600);
    //! [1] //! [2]
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);
    //! [2]
    //! [3]
    Starship ship;
    ship.setPos(QPointF(0,0));
    scene.addItem(&ship);
    //! [4]
    game_scene view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    //! [4] //! [5]
    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setDragMode(QGraphicsView::ScrollHandDrag);
    //! [5] //! [6]
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Starship Trek"));
    view.resize(800, 600);
    view.show();

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &scene, &QGraphicsScene::advance);
    timer.start(1000 / 33);
    return a.exec();
}
