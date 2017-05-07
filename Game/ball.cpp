#include "Game/ball.h"
#include <QPainter>
#include <QGraphicsScene>
#include <QStyleOptionGraphicsItem>
Ball::Ball(QGraphicsItem *parent):GameObject(parent)
{
    init();
}

void Ball::move(QVector2D direction)
{
    direction.normalize();
    direction*=speed;
    auto scenRect=this->scene()->sceneRect();
    auto rect=this->boundingRect();
    rect=mapRectToScene(rect);
    moveBy(direction.x(),direction.y());
}

void Ball::init()
{
    width=25;
    height=25;
    velocity={5,5};
    direction={4,2};
    speed=5;
}

QRectF Ball::boundingRect() const
{
    auto position=scenePos().toPoint();
    return QRectF(position.x(),position.y(),width,height);
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);Q_UNUSED(widget);
    auto position=scenePos();
    position.toPoint();
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    painter->drawRoundRect(position.x(),position.y(),width,height);
    painter->restore();
}
