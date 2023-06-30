#include "myScene.h"
#include "starship.h"
#include "starship.cpp"

#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>

myScene::myScene(){
    ship.setPos(QPointF(0,0));
    this->addItem(&ship);
    setFocusItem(&ship);
}

void myScene::keyPressEvent(QKeyEvent * event){
    int key = event->key();
    switch(key){
    case Qt::Key_W: ship.acceleration = 0.1;break;
    case Qt::Key_S: ship.acceleration = -0.1;break;
    case Qt::Key_A: ship.angular_a -= 0.1;break;
    case Qt::Key_D: ship.angular_a += 0.1;break;
    }
}

void myScene::keyReleaseEvent(QKeyEvent * event){
    int key = event->key();
    switch(key){
    case Qt::Key_W: ship.acceleration = 0;break;
    case Qt::Key_S: ship.acceleration = 0;break;
    case Qt::Key_A: ship.angular_a = 0;break;
    case Qt::Key_D: ship.angular_a = 0;break;
    }
}
