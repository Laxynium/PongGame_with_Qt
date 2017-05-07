#ifndef PADDLE_H
#define PADDLE_H

#include "Game/gameobject.h"
class Paddle:public GameObject
{
public:
    Paddle(QGraphicsItem*parent=nullptr);
    virtual void move(QVector2D direction) override;
    virtual void init() override;       
    // QGraphicsItem interface
public:
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
};

#endif // PADDLE_H
