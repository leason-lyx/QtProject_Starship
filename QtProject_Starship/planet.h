#ifndef PLANET_H
#define PLANET_H

# include <QGraphicsItem>

class Planet: public QGraphicsItem{
public:
    Planet(qreal x, qreal y, qreal r, int color);
    inline QRectF boundingRect() const override;
    inline QPainterPath shape() const override;
    inline void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                      QWidget *widget) override;
    inline int type() const override;
//    inline void advance(int step) override;

    qreal radius;
    qreal mass;
    qreal px, py;
    int color;
};

#endif // PLANET_H
