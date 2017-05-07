#include "Game/gameobject.h"

GameObject::GameObject(QGraphicsItem*parent):QGraphicsItem(parent)
{

}

QPointF GameObject::getDefaultPosition() const
{
    return defaultPosition;
}

void GameObject::setDefaultPosition(QPointF DefaultPostion)
{
    defaultPosition=DefaultPostion;
}

void GameObject::setVelocity(QVector2D nVelocity)
{
    velocity=nVelocity;
}

QVector2D GameObject::getVelocity() const
{
    return velocity;
}

void GameObject::setDirection(QVector2D Direction)
{
    direction=Direction;
}

QVector2D GameObject::getDirection() const
{
    return direction;
}

void GameObject::setSpeed(qreal Speed)
{
    speed=Speed;
}

qreal GameObject::getSpeed() const
{
    return speed;
}

void GameObject::getWidth() const
{
    return width;
}

void GameObject::getHeight() const
{
    return height;
}
