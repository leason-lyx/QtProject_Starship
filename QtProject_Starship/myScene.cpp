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
#include <random>
#include <cmath>

bool validPoint(qreal cx, qreal cy, qreal sx, qreal sy){
    return std::sqrt(std::pow((cx-sx),2)+std::pow((cy-sy),2))>=90;
}

bool myScene::validRandom(qreal x,qreal y){
    return validPoint(x,y,star.px,star.py) && validPoint(x,y,star_2.px,star_2.py)
           && validPoint(x,y,star_3.px,star_3.py) && validPoint(x,y,star_4.px,star_4.py) && validPoint(x,y,star_5.px,star_5.py);
}

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

    std::random_device rd; // 获取真随机数种子
    std::mt19937 generator(rd()); // 使用mt19937引擎
    std::uniform_int_distribution<int> distribution(0, 100); // 生成1到10之间的随机整数

    for(int i = 0; i < 7 ;i++){
        qreal newX=static_cast<qreal>(distribution(generator)) / 100.0 * 720 - 360;
        qreal newY=static_cast<qreal>(distribution(generator)) / 100.0 * 400 - 200;
        std::cerr<<"init "<<newX<<" "<<newY<<std::endl;
        while(!validRandom(newX,newY)){
            newX=static_cast<qreal>(distribution(generator)) / 100.0 * 720 - 360;
            newY=static_cast<qreal>(distribution(generator)) / 100.0 * 400 - 200;
        }
        std::cerr<<newX<<" "<<newY<<std::endl;
        coins[i]=Coin(newX,newY);
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
    qreal tempScore=0;
    for(int i=0;i<7;i++){
        if(coins[i].eaten) tempScore+=10;
    }
    newClock->score=tempScore;
    //QTime currentTime=QTime::currentTime();
    if(Time>=stopTime){
        ship.operate=0;
    }
    if(newClock->life<=0) ship.operate=0;
}
