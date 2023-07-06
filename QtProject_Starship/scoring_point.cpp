#include "scoring_point.h"
#include <random>

scoring_point::scoring_point()
{
    std::random_device rd; // 获取真随机数种子
    std::mt19937 generator(rd()); // 使用mt19937引擎
    std::uniform_int_distribution<int> distribution(1, 98); // 生成1到10之间的随机整数
    qreal xRat=distribution(generator)/98;
    qreal yRat=distribution(generator)/98;
    x=xRat*400;
    y=yRat*400;
}

QRectF scoring_point::boundingRect() const{
    qreal adjust = 0.5;
    return QRectF(-rad - adjust, -rad - adjust,  2 * (rad + adjust), 2 * (rad + adjust));
}

QPainterPath scoring_point::shape() const{
    QPainterPath path;
    path.moveTo(0,rad);
    path.lineTo(rad,2*rad);
    path.lineTo(2*rad,rad);
    path.lineTo(rad,0);
    path.closeSubpath();
    return path;
}
