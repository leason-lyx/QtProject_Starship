//#ifndef STARSHIP_H
//#define STARSHIP_H
#include "starship.h"
#include "planet.h"
#include <QPainter>
#include <QStyleOption>
#include <QtMath>
#include <iostream>
#include <QGraphicsScene>
#include <QTime>

constexpr qreal Pi = M_PI;
constexpr qreal TwoPi = 2 * M_PI;

Starship::Starship(){}
Starship::Starship(QGraphicsItem *x):QGraphicsItem(x){}
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
    path.addEllipse(-8, -20, 16, 16);
    path.addRect(-8, -12, 16, 20);

    path.addRect(-24, 18, 8, 2);
    path.addRect(16, 18, 8, 2);
    return path;
}

void Starship::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    //Header
    QLinearGradient linear(QPointF(-8, -20), QPointF(4, -20));
    if(!detector){
        linear.setColorAt(0, QColorConstants::Svg::goldenrod);
        linear.setColorAt(1, QColorConstants::Svg::lightgoldenrodyellow);
    }
    else{
        linear.setColorAt(0, QColorConstants::Svg::crimson);
        linear.setColorAt(1, QColorConstants::Svg::lightpink);
    }
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

    //Fire
    if(acceleration > 0){
        srand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
        linear = QLinearGradient(QPointF(-8, 7), QPointF(-8, 23));
        linear.setColorAt(0, QColorConstants::Svg::ivory);
        linear.setColorAt(1, QColorConstants::Svg::crimson);
        linear.setSpread(QGradient::PadSpread);
        painter->setPen(Qt::transparent);
        painter->setBrush(linear);
        for(int i = 1; i <= 24; i++){
            qreal x = rand() % 16 - 8; qreal y = rand() % 16 + 7;
            painter->drawEllipse(x, y, 3, 3);
        }
        update();
    }
    if(acceleration < 0){
        srand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
        painter->setPen(QColorConstants::Svg::aliceblue);
        painter->setBrush(QColorConstants::Svg::aliceblue);
        for(int i = 1; i <= 8; i++){
            qreal x = rand() % 8 - 24; qreal y = rand() % 8 + 10;
            qreal z = rand() % 8 + 16; qreal t = rand() % 8 + 10;
            painter->drawEllipse(x, y, 1, 1);
            painter->drawEllipse(z, t, 1, 1);
        }
        update();
    }
    if(angular_a > 0){
        srand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
        painter->setPen(QColorConstants::Svg::lightyellow);
        painter->setBrush(QColorConstants::Svg::lightyellow);
        for(int i = 1; i <= 8; i++){
            qreal x = rand() % 8 - 24; qreal y = rand() % 8 + 20;
            painter->drawEllipse(x, y, 1, 1);
        }
        for(int i = 1; i <= 8; i++){
            qreal x = rand() % 8 + 16; qreal y = rand() % 8 + 10;
            painter->drawEllipse(x, y, 1, 1);
        }
        update();
    }
    if(angular_a < 0){
        srand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
        painter->setPen(QColorConstants::Svg::lightyellow);
        painter->setBrush(QColorConstants::Svg::lightyellow);
        for(int i = 1; i <= 8; i++){
            qreal x = rand() % 8 + 16; qreal y = rand() % 8 + 20;
            painter->drawEllipse(x, y, 1, 1);
        }
        for(int i = 1; i <= 8; i++){
            qreal x = rand() % 8 - 24; qreal y = rand() % 8 + 10;
            painter->drawEllipse(x, y, 1, 1);
        }
        update();
    }
}

//只检测对星球的碰撞
QList<QGraphicsItem*> QGraphicsScene::collidingItems(const QGraphicsItem* item, Qt::ItemSelectionMode mode) const{
    QList<QGraphicsItem*> allItems = this->items();
    QList<QGraphicsItem*> collidingPlanets;
    foreach(QGraphicsItem* anotherItem, allItems){
        if(anotherItem == item)continue;
        if(anotherItem->type()==Planet::UserType + 1)
            if(item->collidesWithItem(anotherItem, mode))
                collidingPlanets.append(anotherItem);
    }
    return collidingPlanets;
}

int Starship::type() const{
    return Starship::UserType + 2;
}

void Starship::advance(int step){
    std::cerr<<this->operate<<std::endl;
    if(!step || life<=0 || !operate)return;
//    if(!operate || !step)return ;
    else{
        //gravity
        QList<QGraphicsItem*> dangerPlanets;
        QList<QGraphicsItem*> allItems = this->scene()->items();
        foreach(QGraphicsItem* anotherItem, allItems){
            if(anotherItem == this)continue;
            if(anotherItem->type()==Planet::UserType + 1){
                QLineF linetoPlanet(QPointF(0,0), mapFromItem(anotherItem, 0, 0));
                if(linetoPlanet.length() <= 150){
                    dangerPlanets.append(anotherItem);
                    qreal r = linetoPlanet.length();
                    qreal dx = linetoPlanet.dx(), dy = linetoPlanet.dy();
                    qreal beta = atan2(dy, dx);
                    normalizeAngle(beta);
                    Planet* p = dynamic_cast<Planet*>(anotherItem);
                    qreal G = 0.05 * p->mass/(r);
                    gravity_y -= G * sin(beta);
                    gravity_x += G * cos(beta);
                }
            }
        }
        if(!dangerPlanets.isEmpty())detector = 1;
        else {
            detector = 0;
            gravity_x = 0;
            gravity_y = 0;
        }

        if(!scene()->collidingItems(this, Qt::IntersectsItemShape).isEmpty()){
            if(fabs(velocity) <= 4)impulse = - velocity * 1.6;
            else impulse = -velocity * 1.8;
            impulse_x = -velocity_x * 1.8;
            angular_I = - angular_v * 1.8;
            setPos(mapToParent(-velocity_x - 0.1 * velocity_x/fabs(velocity_x), velocity + 0.1 * velocity/fabs(velocity)));
            angle = angle - angular_v;
            setRotation(angle);
            if(impulse_x * impulse_x + impulse * impulse > 10)
                life -= (impulse_x * impulse_x + impulse * impulse) * 0.3;
            if(angular_I > 2)
                life -= angular_I * 0.3;
        }
        else{
            impulse = 0;
            impulse_x = 0;
            angular_I = 0;

        }

        //velocity
        velocity = velocity + acceleration + impulse + gravity_y;
        if(velocity >= 5)velocity = 5;
        if(velocity <= -3)velocity = -3;
        if(acceleration == 0 && velocity > 0) velocity -= 0.01;
        else if(acceleration == 0 && velocity < 0) velocity += 0.01;

        if(velocity_x > 0) velocity_x -= 0.01;
        else if(velocity_x < 0) velocity_x += 0.01;

        //velocity_x
        velocity_x = velocity_x + impulse_x + gravity_x;

    
        //angular velocity
        angular_v = angular_v + angular_a + angular_I;
        angle = angle + angular_v;
        if(angular_v >= 3)angular_v = 3;
        if(angular_v <= -3)angular_v = -3;
        if(angular_a == 0 && angular_v > 0) angular_v -= 0.01;
        else if(angular_a == 0 && angular_v < 0) angular_v += 0.01;
    
        normalizeAngle(angle);
        setRotation(angle);
        setPos(mapToParent(velocity_x, -velocity));
        gravity_y = 0;
        gravity_x = 0;
    }
}
