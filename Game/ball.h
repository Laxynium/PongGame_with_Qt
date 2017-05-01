#ifndef BALL_H
#define BALL_H

#include "Game/gameobject.h"

class Ball:public GameObject
{
public:
    Ball(QGraphicsItem*parent=nullptr);
    virtual void move(QVector2D direction) override;
    virtual void setSpeed(QVector2D nSpeed) override;
    virtual QVector2D getSpeed() const override;
    virtual void init() override;
     QVector2D getBallDirection()const;
     void setBallDirection(QVector2D dir);
public:
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
    QVector2D speed={5,5};
    QVector2D ballDirection{4,2};
    int width=25;
    int height=25;
};

#endif // BALL_H
