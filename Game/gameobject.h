#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsItem>

#include <QVector2D>

class GameObject:public QGraphicsItem
{
public:
    GameObject(QGraphicsItem*parent=nullptr);

    virtual void move(QVector2D direction)=0; 
    virtual void init()=0;

    virtual QPointF getDefaultPosition()const;
    virtual void setDefaultPosition(QPointF DefaultPostion);

    virtual void setVelocity(QVector2D nVelocity);
    virtual QVector2D getVelocity()const;

    virtual void setDirection(QVector2D Direction);
    virtual QVector2D getDirection()const;

    virtual void setSpeed(qreal Speed);
    virtual qreal getSpeed()const;

    void getWidth()const;
    void getHeight()const;

protected:
    QPointF defaultPosition={0,0};
    QVector2D velocity={0,0};
    QVector2D direction={0,0};
    qreal speed=0;
    int width=0;
    int height=0;
};

#endif // GAMEOBJECT_H
