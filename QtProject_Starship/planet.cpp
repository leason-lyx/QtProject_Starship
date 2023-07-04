#include "planet.h"

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QtMath>
#include <Qtime>
#include <QtGlobal>

constexpr qreal Pi = M_PI;
constexpr qreal TwoPi = 2 * M_PI;

Planet::Planet(){
    srand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    radius = rand() % 10 + 50;
    mass = rand() % 10 + 50;
    px = rand() % 50 + 100;
    py = rand() % 50 + 100;
}

QRectF Planet::boundingRect() const{
    qreal adjust = 0.5;
    return QRectF(-radius - adjust, -radius - adjust,  2 * (radius + adjust), 2 * (radius + adjust));
}

QPainterPath Planet::shape() const{
    QPainterPath path;
    path.addEllipse(-radius, -radius, 2 * radius, 2 * radius);
    return path;
}

void Planet::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(QColorConstants::Svg::skyblue);
    painter->setRenderHint(QPainter::Antialiasing, true);
    QRadialGradient radial(0, 0, radius, -0.5*radius, -0.5*radius);
    radial.setColorAt(0, QColorConstants::Svg::skyblue);
    radial.setColorAt(0.8, QColorConstants::Svg::navy);
    radial.setColorAt(1, QColorConstants::Svg::midnightblue);
    radial.setSpread(QGradient::PadSpread);
    painter->setBrush(radial);
    painter->drawEllipse(-radius, -radius, 2 * radius, 2 * radius);
}

int Planet::type() const{
    // 返回自定义的图形项类型
    return Planet::UserType + 1;
}

//void Planet::advance(int step){
//    if(!step)return;
//    else{
//        QList<QGraphicsItem*> dangerPlanets;
//        QList<QGraphicsItem*> allItems = scene()->items();  // 获取场景中的所有图形项

//        foreach (QGraphicsItem* star, allItems) {
//            if (star != this) {  // 排除当前图形项本身
//                QLineF LinetoStar(QPointF(0,0), mapFromItem(star, 0, 0));
//                qreal distance = LinetoStar.length();
//                if (distance <= 100.0) {
//                    dangerPlanets.append(star);
//                }
//            }
//        }

//        for (const QGraphicsItem *star : dangerPlanets){
//            QLineF lineToStar(QPointF(0,0), mapFromItem(star, 0, 0));
//            qreal angleToStar = std::atan2(lineToStar.dy(), lineToStar.dx());
//            qreal gravity =
//        }
//    }
//}
