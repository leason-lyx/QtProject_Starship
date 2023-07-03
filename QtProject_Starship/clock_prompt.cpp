#include "clock_prompt.h"

qreal clock_prompt::TIME_LIMIT=10;
clock_prompt::clock_prompt(){
    timer=new QTimer();
    QObject::connect(timer, &QTimer::timeout, this, &clock_prompt::update_Time);
    timer->start(1000);
}
void clock_prompt::update_Time(){
    seconds++;
    update();
}
//void advance(int step){}
void clock_prompt::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget) {
    QFont font("Arial",12);
    QColor color(Qt::yellow);
    painter->setFont(font);
    painter->setPen(color);
    QRect rect(-200,-200,500,500);
    if(seconds<=clock_prompt::TIME_LIMIT)
    painter->drawText(rect, Qt::AlignCenter, QString("TIME: %1 SECONDS").arg(seconds));
    else
    painter->drawText(rect, Qt::AlignCenter, QString("TIME IS UP, PLEASE EXIT"));
}
QRectF clock_prompt::boundingRect() const {
    return QRectF(-100,-100,200,200);
};
