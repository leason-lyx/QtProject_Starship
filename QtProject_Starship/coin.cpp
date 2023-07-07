#include "coin.h"

#include <random>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QtMath>
#include <Qtime>
#include <QtGlobal>

Coin::Coin(qreal x, qreal y)
{
//    std::random_device rd; // 获取真随机数种子
//    std::mt19937 generator(rd()); // 使用mt19937引擎
//    std::uniform_int_distribution<int> distribution(1, 98); // 生成1到10之间的随机整数
//    qreal xRat=distribution(generator)/98;
//    qreal yRat=distribution(generator)/98;
//    px = xRat + 100;
//    py = yRat + 100;
    px = x, py = y;
}

QRectF Coin::boundingRect() const{
    qreal adjust = 0.5;
    return QRectF(-radius - adjust, -radius - adjust,  2 * (radius + adjust), 2 * (radius + adjust));
}

QPainterPath Coin::shape() const{
    QPainterPath path;
    path.addRect(-radius, -radius, 2 * radius, 2 * radius);
    return path;
}

void Coin::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    if(eaten)return;
    else{
//        painter->setRenderHint(QPainter::Antialiasing, true);
//        QRadialGradient radial(0, 0, radius, -0.5*radius, -0.5*radius);
//        radial.setColorAt(1, QColorConstants::Svg::gold);
//        radial.setColorAt(0, QColorConstants::Svg::lightgoldenrodyellow);
//        radial.setSpread(QGradient::PadSpread);
//        painter->setBrush(radial);
//        painter->drawEllipse(-radius, -radius, 2 * radius, 2 * radius);
        painter->setRenderHint(QPainter::Antialiasing, true);
        QLinearGradient linear(QPointF(0, -10), QPointF(0, 10));
        linear.setColorAt(0, QColorConstants::Svg::ivory);
        linear.setColorAt(0.5, QColorConstants::Svg::peachpuff);
        linear.setColorAt(1, QColorConstants::Svg::dodgerblue);
        linear.setSpread(QGradient::PadSpread);
        painter->setBrush(linear);
        QPoint points[8] = {QPoint(0,-10),QPoint(-6,-6),QPoint(-6,2),QPoint(-10,6),
                            QPoint(0,10),QPoint(10,6),QPoint(6,2),QPoint(6,-6)};
        painter->drawPolygon(points, 8);

        update();
    }
}

int Coin::type() const{
    return Coin::UserType + 3;
}
