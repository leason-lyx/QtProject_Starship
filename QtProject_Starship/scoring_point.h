#ifndef SCORING_POINT_H
#define SCORING_POINT_H

#include <QGraphicsItem>

class scoring_point : public QGraphicsItem
{
public:
    scoring_point();
    qreal x,y;
    bool eaten=0;
    qreal rad=5;
    inline QRectF boundingRect() const override;
    inline QPainterPath shape() const override;
    inline void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                      QWidget *widget) override;
    inline int type() const override;
};

#endif // SCORING_POINT_H
