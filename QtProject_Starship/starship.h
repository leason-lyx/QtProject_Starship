#ifndef STARSHIP_H
#define STARSHIP_H

#include "clock_prompt.h"
#include <QGraphicsItem>
#include <iostream>

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
    inline int type() const override;

    qreal angle = 0;
    qreal angular_v = 0;//角速度
    qreal angular_a = 0;//角加速度
    qreal velocity = 0;//竖向速度
    qreal velocity_x = 0;//横向速度
    qreal acceleration = 0;//喷气加速度
    qreal impulse = 0;//冲量
    qreal impulse_x = 0;//横向冲量
    qreal angular_I = 0;//角冲量
    qreal gravity_y = 0;//重力竖向分量
    qreal gravity_x = 0;//重力横向分量
    qreal field_x = 0, field_y = 0, angular_f = 0;//限制飞船不出边界的力
    bool detector = 0;
    qreal life = MAX_LIFE;
    bool operate=1;
};

#endif // STARSHIP_H
