#ifndef MYSCENE_H
#define MYSCENE_H
//#include "qgraphicsitem.h"
#include "clock_prompt.h"
#include "starship.h"
#include "planet.h"
#include "clock_prompt.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsWidget>
#include <QTime>

class myScene : public QGraphicsScene {
    Q_OBJECT;
public:
//    QList<Planet*> stars;
    Planet star = Planet(300, 100, 50, 1284379128);
    Planet star_2 = Planet(-230, 120, 60, 19854);
    Planet star_3 = Planet(120, -110, 45, 1314322266);
    Planet star_4 = Planet(0, 220, 70, 13144444);
    Planet star_5 = Planet(-250, -160, 50, 234897);
    Starship ship;
    clock_prompt* newClock=new clock_prompt();
    myScene();
    //    ship.setPos(QPointF(0,0));
    //    scene.addItem(&ship);
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    clock_prompt* newClock = new clock_prompt();
    qreal stopTime = 30;
    qreal Time = 0;
public slots:
    void Stop();
    //void checkLife();
};

#endif // MYSCENE_H
