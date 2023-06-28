#include "clock_prompt.h"
#include <winsock.h>
#include <QDateTime>
#include <QTimer>
#include <QFont>
#include <QColor>
#include<QPainter>
#include<QObject>
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
    QFont font("Arial",20);
    QColor color(Qt::yellow);
    painter->setFont(font);
    painter->setPen(color);
    QRect rect(-100,-100,200,200);
    painter->drawText(rect, Qt::AlignCenter, QString("TIME: %1 SECONDS").arg(seconds));
}
QRectF clock_prompt::boundingRect() const {
    return QRectF(-100,-100,200,200);
};
