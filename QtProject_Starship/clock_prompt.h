#ifndef CLOCK_PROMPT_H
#define CLOCK_PROMPT_H

#include <QGraphicsItem>
#include <winsock.h>
#include <QDateTime>
#include <QTimer>
#include <QFont>
#include <QColor>
#include <QPainter>
#include <QObject>

class clock_prompt : public QGraphicsItem, public QObject
{
public:
    static qreal TIME_LIMIT;
    clock_prompt() ;
    QTimer *timer;
    qreal seconds=0;
    void update_Time();
    //void advance(int step);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget) override;
    QRectF boundingRect() const override;
};

#endif // CLOCK_PROMPT_H
