#include "myScene.h"
//#include "starship.h"
//#include "starship.cpp"

//#include <QGraphicsItem>
//#include <QGraphicsView>
//#include <QGraphicsScene>
//#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QList>

myScene::myScene(){
    star.setPos(QPointF(star.px, star.py));
    this->addItem(&star);
    setFocusItem(&star);
    ship.setPos(QPointF(0,0));
    this->addItem(&ship);
    setFocusItem(&ship);
    /*
    QTimer *timer=new QTimer(this);
    timer->setInterval(1000);
    connect(timer,&QTimer::timeout,this,&myScene::Stop);
    timer->start();
    */

}

void myScene::keyPressEvent(QKeyEvent * event){
    int key = event->key();
    switch(key){
    case Qt::Key_W: ship.acceleration = 0.1;break;
    case Qt::Key_S: ship.acceleration = -0.1;break;
    case Qt::Key_A: ship.angular_a = -0.1;break;
    case Qt::Key_D: ship.angular_a = 0.1;break;
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
    Time+=0.5;
    //QTime currentTime=QTime::currentTime();
    if(Time>=stopTime){
        ship.operate=0;
    }
}
