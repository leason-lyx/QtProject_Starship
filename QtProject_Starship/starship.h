#ifndef STARSHIP_H
#define STARSHIP_H

#include <QGraphicsItem>
#include <iostream>

class Starship : public QGraphicsItem
{
public:
    Starship() = default;
    //Starship(QGraphicsItem *item);
    inline QRectF boundingRect() const override;
    inline QPainterPath shape() const override;
    inline void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    inline void advance(int step) override;
    int type() const override;

    qreal angle = 0;
    qreal angular_v = 0;//angular velocity
    qreal angular_a = 0;//angular_acceleration
    qreal velocity = 0;//velocity
    qreal acceleration = 0;
    qreal impulse = 0;//impulse when hit the planet
    qreal angular_I = 0;
    qreal headDirection = 0;
    bool operate=1;
};
#endif // STARSHIP_H
