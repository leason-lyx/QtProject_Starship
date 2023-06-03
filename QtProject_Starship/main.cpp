#include <QApplication>
#include <QtWidgets>
#include <QStyle>

#include "myScene.h"
#include "starship.h"
#include "starship.cpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myScene scene;
    scene.setSceneRect(-300, -300, 600, 600);
    //! [1] //! [2]
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);
    //! [2]
    //! [3]
    Starship ship;
    ship.setPos(QPointF(0,0));
    scene.addItem(&ship);
    //! [4]
    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setBackgroundBrush(QPixmap(":/images/background.jpg"));
    //! [4] //! [5]
    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setDragMode(QGraphicsView::ScrollHandDrag);
    //! [5] //! [6]
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Starship Trek"));
    view.resize(800, 600);
    view.show();
    return a.exec();
}
