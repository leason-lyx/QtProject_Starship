#ifndef PLANET_H
#define PLANET_H

# include <QGraphicsItem>

class Planet: public QGraphicsItem{
public:
    Planet();
    inline QRectF boundingRect() const override;
    inline QPainterPath shape() const override;
    inline void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                      QWidget *widget) override;


    qreal radius;
    qreal mass;
    qreal px, py;
};

#endif // PLANET_H
