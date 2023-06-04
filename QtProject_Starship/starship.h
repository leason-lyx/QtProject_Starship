#ifndef STARSHIP_H
#define STARSHIP_H

#include <QGraphicsItem>

class Starship : public QGraphicsItem
{
public:
    //Starship();

    inline QRectF boundingRect() const override;
    inline QPainterPath shape() const override;
    inline void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    inline void advance(int step) override;

    qreal angle = 0;
    qreal speed = 0;
    qreal acceleration = 0;
    qreal headDirection = 0;
};
#endif // STARSHIP_H
