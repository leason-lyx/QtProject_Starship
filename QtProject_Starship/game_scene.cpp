#include "game_scene.h"
#include <QGraphicsView>
#include <QGraphicsScene>

game_scene::game_scene(QGraphicsScene* scene):QGraphicsView(scene)
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void game_scene::showEvent(QShowEvent* event)
{
    QGraphicsView::showEvent(event);

    QPixmap pixmap(":/images/background2.jpg");
    pixmap = pixmap.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
//    pixmap = pixmap.scaled(this->size(), Qt::KeepAspectRatio);
    QBrush brush(pixmap);
    this->setBackgroundBrush(brush);
}

void game_scene::resizeEvent(QResizeEvent* event)
{
    QGraphicsView::resizeEvent(event);

    QPixmap pixmap(":/images/background.png");
//    pixmap = pixmap.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    pixmap = pixmap.scaled(this->size(),Qt::IgnoreAspectRatio);
    this->setBackgroundBrush(pixmap);
}
