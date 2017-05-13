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

void PlayerPaddleController::setKeyToMoveUp(Qt::Key up)
{
     keyToMoveUp=up;
}

void PlayerPaddleController::setKeyToMoveDown(Qt::Key down)
{
    keyToMoveDown=down;
}

bool PlayerPaddleController::event(QEvent *event)
{
    if(!(event->type()==QEvent::Type::KeyPress||event->type()==QEvent::Type::KeyRelease))
        return false;

    QKeyEvent *keyEvent=static_cast<QKeyEvent*>(event);
    if(keyEvent->isAutoRepeat())return false;

    if(keyEvent->key()==keyToMoveUp)
    {
        rev=-1;
    }
     if(keyEvent->key()==keyToMoveDown)
    {
        rev=1;
    }
    if(keyEvent->key()==keyToMoveUp||keyEvent->key()==keyToMoveDown)
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
