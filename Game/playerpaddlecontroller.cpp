#include "playerpaddlecontroller.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>
#include <QTimer>
PlayerPaddleController::PlayerPaddleController(QObject *parent, std::shared_ptr<GameObject> newControlledObject):GameObjectController(parent),
    timer(new QTimer())
{
    timer->setInterval(15);
    connect(timer,&QTimer::timeout,this,[this](){QVector2D direction{0,4};
        controlledObject->move(direction*rev);});
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
    //do nothing
    if(!controlledObject)
    {
        qDebug()<<"ControlledObject isn't set\n";
        return ;
    }
}

bool PlayerPaddleController::event(QEvent *event)
{
    if(!(event->type()==QEvent::Type::KeyPress||event->type()==QEvent::Type::KeyRelease))
        return false;

    //TODO This should be moved to other function or class
    QKeyEvent *keyEvent=static_cast<QKeyEvent*>(event);
    if(keyEvent->isAutoRepeat())return false;

    if(keyEvent->key()==Qt::Key_W)
    {
        rev=-1;
    }
     if(keyEvent->key()==Qt::Key_S)
    {
        rev=1;
    }
    if(keyEvent->key()==Qt::Key_W||keyEvent->key()==Qt::Key_S)
    {
        if(event->type()==QEvent::Type::KeyPress)
        {
            timer->start();
        }
        if(event->type()==QEvent::Type::KeyRelease)
        {
            timer->stop();
        }
    }


    return true;
}
