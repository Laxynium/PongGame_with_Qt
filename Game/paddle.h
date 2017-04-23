#ifndef PADDLE_H
#define PADDLE_H

#include "Game/gameobject.h"
class Paddle:public GameObject
{
public:
    Paddle(QGraphicsItem*parent=nullptr);
};

#endif // PADDLE_H
