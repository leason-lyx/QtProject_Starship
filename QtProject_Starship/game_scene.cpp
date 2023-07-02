#include "game_scene.h"
#include "starship.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QTime>

game_scene::game_scene(QGraphicsScene* scene):QGraphicsView(scene)
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QTimer *timer=new QTimer(this);
    timer->setInterval(1000);
    connect(timer,&QTimer::timeout,this,&game_scene::Stop);
    timer->start();
    stopTime=QTime(0,0,10);
}

void game_scene::showEvent(QShowEvent* event)
{
    QGraphicsView::showEvent(event);

    QPixmap pixmap(":/images/background4.jpg");
    pixmap = pixmap.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    pixmap = pixmap.scaled(this->size(), Qt::KeepAspectRatio);
    QBrush brush(pixmap);
    this->setBackgroundBrush(brush);
}

void game_scene::resizeEvent(QResizeEvent* event)
{
    QGraphicsView::resizeEvent(event);

    QPixmap pixmap(":/images/background4.jpg");
    pixmap = pixmap.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    pixmap = pixmap.scaled(this->size(),Qt::IgnoreAspectRatio);
    this->setBackgroundBrush(pixmap);
}

void game_scene::Stop(){
    QTime currentTime=QTime::currentTime();
    if(currentTime>=this->stopTime){
        QList<QGraphicsItem *> itemList=items();
        for(QGraphicsItem *item : itemList){
            Starship *sitem=dynamic_cast<Starship*>(item);
            sitem->operate=0;
        }
    }
}
