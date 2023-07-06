#include "planet.h"
#include "starship.h"

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QtMath>
#include <Qtime>
#include <QtGlobal>

constexpr qreal Pi = M_PI;
constexpr qreal TwoPi = 2 * M_PI;

Planet::Planet(qreal x, qreal y, qreal r, int c){
    srand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    px = x, py = y, radius = r, color = c;
    mass = radius;
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
//    painter->setBrush(QColorConstants::Svg::skyblue);
    painter->setRenderHint(QPainter::Antialiasing, true);
    QRadialGradient radial(0, 0, radius, -0.5*radius, -0.5*radius);
    radial.setColorAt(0, QColor(color));
    radial.setColorAt(0.8, QColor(color + 100));
    radial.setColorAt(1, QColor(color - 100));
    radial.setSpread(QGradient::PadSpread);
    painter->setBrush(radial);
    painter->drawEllipse(-radius, -radius, 2 * radius, 2 * radius);
}

int Planet::type() const{
    // 返回自定义的图形项类型
    return Planet::UserType + 1;
}
