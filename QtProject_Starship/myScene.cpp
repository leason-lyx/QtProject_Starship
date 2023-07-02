#include "myScene.h"
#include "starship.h"
#include "starship.cpp"

#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QList>

myScene::myScene(){
    ship.setPos(QPointF(0,0));
    this->addItem(&ship);
    setFocusItem(&ship);
    /*
    QTimer *timer=new QTimer(this);
    timer->setInterval(1000);
    connect(timer,&QTimer::timeout,this,&myScene::Stop);
    timer->start();
    stopTime=QTime(0,0,10);
*/
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

void myScene::Stop(){
    QTime currentTime=QTime::currentTime();
    if(currentTime>=this->stopTime){
        QList<QGraphicsItem *> itemList=items();
        for(QGraphicsItem *item : itemList){
            Starship *sitem=dynamic_cast<Starship*>(item);
            sitem->operate=0;
        }
    }
}
