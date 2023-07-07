#include "clock_prompt.h"
#include <iostream>

//const qreal DAMAGE_RATIO=0.25;
qreal clock_prompt::TIME_LIMIT=30;
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
    QFont font;
    font.setFamily("Arial");
    font.setPointSize(12);//文字大小
    QColor color(Qt::yellow);
    QColor colorEx(210,180,140);
    QColor ColorIn(255,0,0);
    painter->setFont(font);
    painter->setPen(color);
    QRect rect(-100,-100,200,50);
    QRect rectEx(-100,-50,200,20);
    if(seconds<=clock_prompt::TIME_LIMIT && life>0){
        painter->drawText(rect, Qt::AlignCenter, QString("TIME: %1 SECONDS").arg(seconds));
        painter->setBrush(colorEx);
        painter->drawRect(rectEx);
        qreal DAMAGE_RATIO = life/MAX_LIFE;
        QRect rectIn(-100,-50,200 * DAMAGE_RATIO,20);
        painter->setBrush(ColorIn);
        painter->drawRect(rectIn);
//        update();
    }
    else if(life<=0){
        painter->drawText(rect, Qt::AlignCenter, QString("CRASHHHED!"));
        painter->setBrush(colorEx);
        painter->drawRect(rectEx);
//        update();
    }
    else if(seconds>clock_prompt::TIME_LIMIT){
        painter->drawText(rect, Qt::AlignCenter, QString("TIME IS UP! PLEASE EXIT"));
        painter->setBrush(colorEx);
        painter->drawRect(rectEx);
        qreal DAMAGE_RATIO=life/MAX_LIFE;
        QRect rectIn(-100,-50,200 * DAMAGE_RATIO,20);
        painter->setBrush(ColorIn);
        painter->drawRect(rectIn);
//        update();
    }
}
QRectF clock_prompt::boundingRect() const {
    return QRectF(-100,-100,200,70);
};
void clock_prompt::checkLife(){

}

void clock_prompt::advance(int step){
    if(!step)return;
    else update();
}
