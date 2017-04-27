#include "playerpaddlecontroller.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>
PlayerPaddleController::PlayerPaddleController(QObject *parent, std::shared_ptr<GameObject> newControlledObject):GameObjectController(parent)
{

}
void PlayerPaddleController::setControlledObject(std::shared_ptr<GameObject> newControlledObject)
{
    controlledObject=newControlledObject;
}

std::shared_ptr<GameObject> PlayerPaddleController::getControlledObject()
{
    return controlledObject;
}

void PlayerPaddleController::Tick()
{
    if(!controlledObject)
    {
        qDebug()<<"ControlledObject isn't set\n";
        return ;
    }
    QVector2D direction{0,4};
    auto sceneRect=controlledObject->scene()->sceneRect();
    auto objectRect=controlledObject->boundingRect();
    objectRect=controlledObject->mapRectToScene(objectRect);
    if(objectRect.bottom()>=sceneRect.bottom())
        rev=-1;
    if(objectRect.top()<=sceneRect.top())
        rev=1;
    controlledObject->move(direction*rev);
}

bool PlayerPaddleController::event(QEvent *event)
{
    if(!(event->type()==QEvent::Type::KeyPress||event->type()==QEvent::Type::KeyRelease))
        return false;

    QKeyEvent *keyEvent=static_cast<QKeyEvent*>(event);
   // if(keyEvent->isAutoRepeat())return false;
    if(keyEvent->key()==Qt::Key_W)
    {
        controlledObject->move(QVector2D(0,-4));
    }else
    if(keyEvent->key()==Qt::Key_S)
    {
        controlledObject->move(QVector2D(0,4));
    }

    return true;
}
