#include "clock_prompt.h"
#include "myScene.h"

#include <iostream>
#include <QFont>

//const qreal DAMAGE_RATIO=0.25;
qreal clock_prompt::TIME_LIMIT=40;
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
    font.setFamily("Terminal");
    font.setPointSize(12);//文字大小
    QColor color(Qt::yellow);
    QColor colorEx(210,180,140);
    QColor ColorIn(255,0,0);
    painter->setFont(font);
    painter->setPen(color);
    QRect rect(-100,-100,200,50);
    QRect rectEx(-100,-50,200,20);
    QRect rectForCoin(-110,-150,210,80);


    if(seconds<=clock_prompt::TIME_LIMIT && life>0){
        std::cerr<<"score:"<<score<<std::endl;
        painter->drawText(rectForCoin, Qt::AlignCenter, QString("SCORE: %1 POINT(S)").arg(score));
        painter->drawText(rect, Qt::AlignCenter, QString("TIME: %1 SECONDS").arg(40 - seconds));
        painter->setBrush(colorEx);
        painter->drawRect(rectEx);
        qreal DAMAGE_RATIO = life/MAX_LIFE;
        QRect rectIn(-100,-50,200 * DAMAGE_RATIO,20);
//        painter->setBrush(ColorIn);
        painter->setRenderHint(QPainter::Antialiasing, true);
        QLinearGradient linear(QPointF(-100, 0), QPointF(100, 0));
        linear.setColorAt(0, QColorConstants::Svg::turquoise);
        linear.setColorAt(0.5, QColorConstants::Svg::paleturquoise);
        linear.setColorAt(1, QColorConstants::Svg::ivory);
        linear.setSpread(QGradient::PadSpread);
        painter->setBrush(linear);
        painter->drawRect(rectIn);
        update();
    }
    else if(life<=0){
        painter->drawText(rect, Qt::AlignCenter, QString("CRASHHHED!"));
        painter->drawText(rectForCoin, Qt::AlignCenter, QString("FINAL SCORE: %1 POINT(S)").arg(score));
        painter->setBrush(colorEx);
        painter->drawRect(rectEx);
        update();
    }
    else if(seconds>=clock_prompt::TIME_LIMIT){
        painter->drawText(rect, Qt::AlignCenter, QString("TIME IS UP!"));
        painter->drawText(rectForCoin, Qt::AlignCenter, QString("FINAL SCORE: %1 POINT(S)").arg(score));
        painter->setBrush(colorEx);
        painter->drawRect(rectEx);
        qreal DAMAGE_RATIO=life/MAX_LIFE;
        QRect rectIn(-100,-50,200 * DAMAGE_RATIO,20);
//        painter->setBrush(ColorIn);
        painter->setRenderHint(QPainter::Antialiasing, true);
        QLinearGradient linear(QPointF(-100, 0), QPointF(100, 0));
        linear.setColorAt(0, QColorConstants::Svg::turquoise);
        linear.setColorAt(0.5, QColorConstants::Svg::paleturquoise);
        linear.setColorAt(1, QColorConstants::Svg::ivory);
        linear.setSpread(QGradient::PadSpread);
        painter->setBrush(linear);
        painter->drawRect(rectIn);
        update();
    }
}
QRectF clock_prompt::boundingRect() const {
    return QRectF(-100,-100,200,70);
};
void clock_prompt::checkLife(){

}

void clock_prompt::advance(int step){
    if(!step)return;
    else{
        myScene* space = dynamic_cast<myScene*>(this -> scene());
        life = space -> ship.life;
        score = space -> ship.score;
        update();
    }
}
