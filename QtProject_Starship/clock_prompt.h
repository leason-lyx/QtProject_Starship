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

const qreal MAX_LIFE=50;
const qreal PER_DAMAGE=5;
class clock_prompt : public QGraphicsItem, public QObject
{
public:
    static qreal TIME_LIMIT;
    clock_prompt() ;
    QTimer *timer;
    qreal seconds=0;
    qreal life=MAX_LIFE;
    qreal score=0;
    void update_Time();
    //void advance(int step);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget) override;
    QRectF boundingRect() const override;
    void checkLife();

    inline void advance(int step) override;
};

#endif // CLOCK_PROMPT_H
