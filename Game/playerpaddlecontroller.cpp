#include "playerpaddlecontroller.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>
#include <QTimer>
PlayerPaddleController::PlayerPaddleController(QObject *parent, std::shared_ptr<GameObject> newControlledObject):GameObjectController(parent),
    timerHelpingWtihMovement(new QTimer())
{
    timerHelpingWtihMovement->setInterval(15);
    connect(timerHelpingWtihMovement,&QTimer::timeout,this,[this](){QVector2D direction{0,4};
        controlledObject->move(direction*reversal);});
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
        reversal=-1;
    }
     if(keyEvent->key()==keyToMoveDown)
    {
        reversal=1;
    }
    if(keyEvent->key()==keyToMoveUp||keyEvent->key()==keyToMoveDown)
    {
        if(event->type()==QEvent::Type::KeyPress)
        {
            timerHelpingWtihMovement->start();
        }
        if(event->type()==QEvent::Type::KeyRelease)
        {
            timerHelpingWtihMovement->stop();
        }
    }
    return true;
}
