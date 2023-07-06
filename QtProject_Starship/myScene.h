#ifndef MYSCENE_H
#define MYSCENE_H
//#include "qgraphicsitem.h"
#include "clock_prompt.h"
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
    clock_prompt* newClock=new clock_prompt();
    myScene();
    //    ship.setPos(QPointF(0,0));
    //    scene.addItem(&ship);
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    qreal stopTime=10;
    qreal Time=0;
public slots:
    void Stop();
    //void checkLife();
};

#endif // MYSCENE_H
