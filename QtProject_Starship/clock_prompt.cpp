#include "clock_prompt.h"
#include <iostream>

//const qreal DAMAGE_RATIO=0.25;
qreal clock_prompt::TIME_LIMIT=10;
clock_prompt::clock_prompt(){
    timer=new QTimer();
    QObject::connect(timer, &QTimer::timeout, this, &clock_prompt::update_Time);
    timer->start(1000);
}
void clock_prompt::update_Time(){
    std::cerr<<seconds<<" ";
    seconds++;
    update();
}
//void advance(int step){}
void clock_prompt::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget) {
    std::cerr<<"ptint"<<std::endl;
    QFont font("Arial",12);
    QColor color(Qt::yellow);
    QColor colorEx(210,180,140);
    QColor ColorIn(255,0,0);
    painter->setFont(font);
    painter->setPen(color);
    QRect rect(-100,-100,200,50);
    QRect rectEx(-100,-50,200,20);
    QRect rectIn(-100,-50,200,20);
    if(seconds<=clock_prompt::TIME_LIMIT && life>0){
        painter->drawText(rect, Qt::AlignCenter, QString("TIME: %1 SECONDS").arg(seconds));
        painter->setBrush(colorEx);
        painter->drawRect(rectEx);
        qreal DAMAGE_RATIO=life/MAX_LIFE;
        rectIn.adjust(0,0,-DAMAGE_RATIO*200,0);
        painter->setBrush(ColorIn);
        painter->drawRect(rectIn);
    }
    else if(life<=0){
        painter->drawText(rect, Qt::AlignCenter, QString("YOU CRASHED, PLEASE EXIT"));
        painter->setBrush(colorEx);
        painter->drawRect(rectEx);
    }
    else if(seconds>clock_prompt::TIME_LIMIT){
        painter->drawText(rect, Qt::AlignCenter, QString("TIME IS UP, PLEASE EXIT"));
        painter->setBrush(colorEx);
        painter->drawRect(rectEx);
        qreal DAMAGE_RATIO=life/MAX_LIFE;
        rectIn.adjust(0,0,-DAMAGE_RATIO*200,0);
        painter->setBrush(ColorIn);
        painter->drawRect(rectIn);
    }
}
QRectF clock_prompt::boundingRect() const {
    return QRectF(-100,-100,200,70);
};
void clock_prompt::checkLife(){

}
