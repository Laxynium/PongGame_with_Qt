#ifndef PADDLE_H
#define PADDLE_H

#include "Game/gameobject.h"
class Paddle:public GameObject
{
public:
    Paddle(QGraphicsItem*parent=nullptr);
    virtual void move(QVector2D direction) override;
    virtual void setSpeed(QVector2D nSpeed) override;
    virtual QVector2D getSpeed() const override;
    virtual void init() override;       
    // QGraphicsItem interface
public:
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
    QVector2D speed={0,3};
    int width=20;
    int height=100;

};

#endif // PADDLE_H
