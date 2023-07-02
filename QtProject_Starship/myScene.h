#ifndef MYSCENE_H
#define MYSCENE_H
//#include "qgraphicsitem.h"
#include "qdatetime.h"
#include "starship.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsWidget>
#include <QTime>

class myScene : public QGraphicsScene {
    Q_OBJECT;
public:
    Starship ship;
    myScene();
    //    ship.setPos(QPointF(0,0));
    //    scene.addItem(&ship);
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    QTime stopTime;
private slots:
    void Stop();
};

#endif // MYSCENE_H
