#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsItem>

#include <QVector2D>

class GameObject:public QGraphicsItem
{
public:
    GameObject(QGraphicsItem*parent=nullptr);
    virtual void move(QVector2D direction)=0;
    virtual void setSpeed(QVector2D nSpeed)=0;
    virtual QVector2D getSpeed()const=0;
    virtual void init()=0;
};

#endif // GAMEOBJECT_H
