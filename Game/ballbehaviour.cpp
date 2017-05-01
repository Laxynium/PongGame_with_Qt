#include "ballbehaviour.h"
#include <QGraphicsScene>
#include <QList>
#include <QTimer>
#include <QTime>
#include <QDebug>
#include <Game/ball.h>
//ball bahaviours:
//reset ball to  start possition and choose random angle
//if ball hit paddle reflect it with proper angle
//
BallBehaviour::BallBehaviour(QObject *parent):GameObjectController(parent)
{

}

void BallBehaviour::setControlledObject(std::shared_ptr<GameObject> newControlledObject)
{
    controlledObject=newControlledObject;
}

std::shared_ptr<GameObject> BallBehaviour::getControlledObject()
{
    return controlledObject;
}

void BallBehaviour::Tick()
{
    if(!controlledObject)
    {
        qDebug()<<"Controlled object not set\n";
        return;
    }

   auto sceneRect=controlledObject->scene()->sceneRect();
   auto ballRect=controlledObject->boundingRect();
   ballRect=controlledObject->mapRectToScene(ballRect);
   if(ballRect.top()<=sceneRect.top())
   {
       ballDirection.setY(-ballDirection.y());
   }
   if(ballRect.bottom()>=sceneRect.bottom())
   {
        ballDirection.setY(-ballDirection.y());
   }
   auto scene=controlledObject->scene();
   auto items=scene->collidingItems(controlledObject.get());
   if(!items.empty())
   {
       //This code solves multireflections
       auto currTime=QTime::currentTime();
       if(currTime.msecsSinceStartOfDay()-lastTime.msecsSinceStartOfDay()>colisionDeley)
       {
            ballDirection.setX(-ballDirection.x());
       }
        lastTime=QTime::currentTime();
   }
   auto ball=static_cast<Ball*>(controlledObject.get());
   ball->setBallDirection(ballDirection);
   controlledObject->move(ballDirection);
   if(ballRect.left()>=sceneRect.right())
   {
        emit ballLeftScene(true);
   }
   if(ballRect.right()<=sceneRect.left())
   {
      emit ballLeftScene(false);
   }
}
