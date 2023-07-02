#ifndef STARSHIP_H
#define STARSHIP_H

#include <QGraphicsItem>

class Starship : public QGraphicsItem
{
public:
    Starship();
    Starship(QGraphicsItem *item);
    inline QRectF boundingRect() const override;
    inline QPainterPath shape() const override;
    inline void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    inline void advance(int step) override;

    qreal angle = 0;
    qreal angular_v = 0;//angular velocity
    qreal angular_a = 0;//angular_acceleration
    qreal velocity = 0;//velocity
    qreal acceleration = 0;
    qreal headDirection = 0;
    bool operate=1;
};
#endif // STARSHIP_H
