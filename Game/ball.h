#ifndef BALL_H
#define BALL_H

#include "Game/gameobject.h"

class Ball:public GameObject
{
public:
    Ball(QGraphicsItem*parent=nullptr);
};

#endif // BALL_H
