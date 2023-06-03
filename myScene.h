#ifndef MYSCENE_H
#define MYSCENE_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainterPath>
#include <QPixmap>
#include <QDebug>

class myScene : public QGraphicsScene {
public:
        Q_OBJECT
public:
        myScene(QWidget *parent = nullptr);
        ~myScene();
        void drawBackground(QPainter painter, const QRectF &rect);
};

#endif // MYSCENE_H
