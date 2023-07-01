#include "starship.h"

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QtMath>

constexpr qreal Pi = M_PI;
constexpr qreal TwoPi = 2 * M_PI;

//Starship::Starship(){}

static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
        angle += TwoPi;
    while (angle > TwoPi)
        angle -= TwoPi;
    return angle;
}

QRectF Starship::boundingRect() const{
    qreal adjust = 0.5;
    return QRectF(-28 - adjust, -24 - adjust, 56 + 2 * adjust, 48 + 2 * adjust);
}

QPainterPath Starship::shape() const{
    QPainterPath path;
    path.addRect(-8, -8, 16, 28);
    return path;
}

void Starship::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    //Header
    QLinearGradient linear(QPointF(-8, -20), QPointF(4, -20));
    linear.setColorAt(0, QColorConstants::Svg::goldenrod);
    linear.setColorAt(1, QColorConstants::Svg::lightgoldenrodyellow);
    //    painter->setBrush(QColorConstants::Svg::goldenrod);
    linear.setSpread(QGradient::PadSpread);
    painter->setBrush(linear);
    painter->drawEllipse(-8, -20, 16, 16);

    //Body
    linear = QLinearGradient(QPointF(-8, -12), QPointF(4, -12));
    linear.setColorAt(0, QColorConstants::Svg::gray);
    linear.setColorAt(1, QColorConstants::Svg::floralwhite);
    linear.setSpread(QGradient::PadSpread);
    painter->setBrush(linear);
    //    painter->setBrush(QColorConstants::Svg::floralwhite);
    painter->drawRect(-8, -12, 16, 20);

    //Legs
    linear = QLinearGradient(QPointF(-20, -20), QPointF(20, -20));
    linear.setColorAt(0, QColorConstants::Svg::saddlebrown);
    linear.setColorAt(1, QColorConstants::Svg::sienna);
    linear.setSpread(QGradient::PadSpread);
    painter->setBrush(linear);
    //    painter->setBrush(QColorConstants::Svg::sienna);
    QPoint pointL[3], pointR[3];
    pointL[0].setX(-8);pointL[0].setY(0);
    pointL[1].setX(-8);pointL[1].setY(8);
    pointL[2].setX(-20);pointL[2].setY(20);
    pointR[0].setX(8);pointR[0].setY(0);
    pointR[1].setX(8);pointR[1].setY(8);
    pointR[2].setX(20);pointR[2].setY(20);
    painter->drawPolygon(pointL, 3);
    painter->drawPolygon(pointR, 3);

    //Engines
    linear = QLinearGradient(QPointF(-24, -20), QPointF(24, -20));
    linear.setColorAt(0, QColorConstants::Svg::burlywood);
    linear.setColorAt(1, QColorConstants::Svg::wheat);
    linear.setSpread(QGradient::PadSpread);
    painter->setBrush(linear);
    //    painter->setBrush(QColorConstants::Svg::burlywood);
    painter->drawRect(-24, 18, 8, 2);
    painter->drawRect(16, 18, 8, 2);
}

void Starship::advance(int step){
    if(!step)return;
    else{
        //velocity
        velocity = velocity + acceleration;
        if(velocity >= 5)velocity = 5;
        if(velocity <= -3)velocity = -3;
        if(acceleration == 0 && velocity > 0) velocity -= 0.01;
        else if(acceleration == 0 && velocity < 0) velocity += 0.01;

        //angular velocity
        angular_v = angular_v + angular_a;
        angle = angle + angular_v;
        if(angular_v >= 3)angular_v = 3;
        if(angular_v <= -3)angular_v = -3;
        if(angular_a == 0 && angular_v > 0) angular_v -= 0.1;
        else if(angular_a == 0 && angular_v < 0) angular_v += 0.1;

        setRotation(angle);
        setPos(mapToParent(0, -velocity));
    }
}
