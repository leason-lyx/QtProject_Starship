#include "myScene.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainterPath>
#include <QPixmap>
#include <QDebug>

myScene::myScene(QWidget *parent):QGraphicsScene(parent){
}

myScene::~myScene(){}

void myScene::drawBackground(QPainter painter, const QRectF &rect){
    //QPixmap map=QPixmap(":/images/background.jpg");
    //painter.drawPixmap(rect,map,QRect());

    if(views().count()==0)return;
    // 计算视窗的大小,消除图元拖动时出现的残影
    QGraphicsView* pView=views().first();
    QRect contentRect=pView->viewport()->contentsRect();
    QRectF sceneRect =pView->mapToScene(contentRect).boundingRect();

    //绘制指定图片作为背景
    QPixmap pixmap("D:/linux-share-dir/test/www/123.jpg");
    painter.drawPixmap(sceneRect,pixmap,QRect());
}
