#ifndef COIN_H
#define COIN_H

#include <QGraphicsItem>

class Coin : public QGraphicsItem
{
public:
    Coin(qreal x, qreal y);
    Coin();
    void operator=(const Coin &x);
    qreal px, py;
    bool eaten = 0;
    qreal radius = 10;
    inline QRectF boundingRect() const override;
    inline QPainterPath shape() const override;
    inline void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                      QWidget *widget) override;
    inline int type() const override;
};

#endif // COIN_H
