#ifndef MYSCENE_H
#define MYSCENE_H
//#include "qgraphicsitem.h"
#include "starship.h"
#include "planet.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsWidget>
#include <QTime>

class myScene : public QGraphicsScene {
    Q_OBJECT;
public:
    Planet star;
    Starship ship;
    myScene();
    //    ship.setPos(QPointF(0,0));
    //    scene.addItem(&ship);
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    qreal stopTime=10;
    qreal Time=0;
public slots:
    void Stop();
};

#endif // MYSCENE_H
