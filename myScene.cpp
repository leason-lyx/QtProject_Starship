#include "myScene.h"

#include <QGraphicsView>
#include <QGraphicsScene>

void myScene::drawBackground(QPainter painter, const QRectF &rect){
    QPixmap map=QPixmap(":/images/background.jpg");
    painter.drawPixmap(rect,map,QRect());
}
