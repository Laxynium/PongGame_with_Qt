#include "Game/ball.h"
#include <QPainter>
#include <QGraphicsScene>
Ball::Ball(QGraphicsItem *parent):GameObject(parent)
{

}

void Ball::move(QVector2D direction)
{
    direction.normalize();
    direction*=speed;
    auto scenRect=this->scene()->sceneRect();
    auto rect=this->boundingRect();
    rect=mapRectToScene(rect);
    rect.setBottom(rect.bottom()+direction.toPointF().y());
    rect.setTop(rect.top()+direction.toPointF().y());
    rect.setLeft(rect.left()+direction.toPoint().x());
    rect.setRight(rect.left()+direction.toPoint().x());
    if(rect.top()<scenRect.top()||
       rect.bottom()>=scenRect.bottom()||
       rect.left()<scenRect.left()||
       rect.right()>=scenRect.right())
       return;
    moveBy(direction.x(),direction.y());
}

void Ball::setSpeed(QVector2D nSpeed)
{
    speed=nSpeed;
}

void Ball::init()
{

}

QRectF Ball::boundingRect() const
{
    auto position=scenePos().toPoint();
    return QRectF(position.x(),position.y(),width,height);
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    auto position=scenePos();
    position.toPoint();
    painter->setBrush(Qt::blue);
    painter->drawEllipse(position.x(),position.y(),width,height);

}
