#ifndef CLOCK_PROMPT_H
#define CLOCK_PROMPT_H

#include <QGraphicsItem>
#include <QObject>

class clock_prompt : public QGraphicsItem, public QObject
{
public:
    clock_prompt() ;
    QTimer *timer;
    qreal seconds=0;
    void update_Time();
    //void advance(int step);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget) override;
    QRectF boundingRect() const override;
};

#endif // CLOCK_PROMPT_H
