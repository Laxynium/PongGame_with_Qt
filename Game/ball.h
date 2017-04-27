#ifndef BALL_H
#define BALL_H

#include "Game/gameobject.h"

class Ball:public GameObject
{
public:
    Ball(QGraphicsItem*parent=nullptr);
    virtual void move(QVector2D direction) override;
    virtual void setSpeed(QVector2D nSpeed) override;
    virtual void init() override;
public:
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
    QVector2D speed={3,3};
    int width=40;
    int height=40;
    // QGraphicsItem interface

};

#endif // BALL_H
