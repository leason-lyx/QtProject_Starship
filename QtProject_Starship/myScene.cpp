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
//    while(stars.size() < 3){
//        Planet star;
//        if(fabs(star.px) > 100 && fabs(star.py) > 100){
//            stars.append(&star);
//            star.setPos(star.px, star.py);
//            this->addItem(&star);
//            setFocusItem(&star);
//        }
//    }
    //5 stars
    star.setPos(QPointF(star.px, star.py));
    this->addItem(&star);
    setFocusItem(&star);
    star_2.setPos(QPointF(star_2.px, star_2.py));
    this->addItem(&star_2);
    setFocusItem(&star_2);
    star_3.setPos(QPointF(star_3.px, star_3.py));
    this->addItem(&star_3);
    setFocusItem(&star_3);
    star_4.setPos(QPointF(star_4.px, star_4.py));
    this->addItem(&star_4);
    setFocusItem(&star_4);
    star_5.setPos(QPointF(star_5.px, star_5.py));
    this->addItem(&star_5);
    setFocusItem(&star_5);

    //clock and life-bar
    newClock->setPos(QPointF(350, -200));
    this->addItem(newClock);
    setFocusItem(newClock);

    //coins
//    coin.setPos(QPointF(coin.px, coin.py));
//    this -> addItem(&coin);
//    setFocusItem(&coin);

    for(int i = 0; i < 7 ;i++){
        coins[i].setPos(QPointF(coins[i].px, coins[i].py));
        this -> addItem(&coins[i]);
        setFocusItem(&coins[i]);
    }

    //starship
    ship.setPos(QPointF(0, 0));
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
    Time+=1;
    newClock->life=ship.life;
    qreal tempScore = ship.score;
//    for(int i=0;i<7;i++){
//        if(coins[i].eaten) tempScore++;
//    }
    newClock->score=tempScore;
//    QTime currentTime=QTime::currentTime();
    if(Time>=stopTime){
        ship.operate=0;
    }
    if(newClock->life<=0) ship.operate=0;
}
