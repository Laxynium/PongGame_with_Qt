#ifndef BALL_H
#define BALL_H

#include "Game/gameobject.h"

class Ball:public GameObject
{
public:
    Ball(QGraphicsItem*parent=nullptr);
    virtual void move(QVector2D direction) override;
    virtual void init() override;
public:
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
};

#endif // BALL_H
