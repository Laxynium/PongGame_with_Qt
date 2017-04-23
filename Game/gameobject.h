#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsItem>


class GameObject:public QGraphicsItem
{
public:
    GameObject(QGraphicsItem*parent=nullptr);
};

#endif // GAMEOBJECT_H
