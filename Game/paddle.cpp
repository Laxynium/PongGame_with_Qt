#include "Game/paddle.h"
#include <QPainter>
#include <QDebug>
#include <QGraphicsScene>
Paddle::Paddle(QGraphicsItem *parent):GameObject(parent)
{
    init();
}

void Paddle::move(QVector2D direction)
{
    direction.normalize();
    direction*=speed;
    auto scenRect=this->scene()->sceneRect();
    auto rect=this->boundingRect();
    rect=mapRectToScene(rect);
    //change paddle rect to check if after change still is in scene
    rect.setBottom(rect.bottom()+direction.toPointF().y());
    rect.setTop(rect.top()+direction.toPointF().y());
    rect.setLeft(rect.left()+direction.toPoint().x());
    rect.setRight(rect.left()+direction.toPoint().x());
    if(rect.top()<scenRect.top()||
       rect.bottom()>=scenRect.bottom()||
       rect.left()<scenRect.left()||
       rect.right()>=scenRect.right())
    {
        return;
    }
    moveBy(direction.x(),direction.y());
}

void Paddle::init()
{
    width=20;
    height=100;
    velocity={0,3};
    speed=3;
    direction={0,0};
}

QRectF Paddle::boundingRect() const
{
     auto position=scenePos().toPoint();
    return QRectF(position.x(),position.y(),width,height);
}

void Paddle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);Q_UNUSED(widget);
    auto position=scenePos();
    position.toPoint();
    painter->setBrush(Qt::blue);
    painter->drawRect(position.x(),position.y(),width,height);
}
