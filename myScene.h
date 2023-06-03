#ifndef MYSCENE_H
#define MYSCENE_H
#include <QGraphicsView>
#include <QGraphicsScene>

class myScene : public QGraphicsScene {
public:
    void drawBackground(QPainter painter, const QRectF &rect);
};

#endif // MYSCENE_H
