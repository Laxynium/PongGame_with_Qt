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

    //checks if ball hit top or bottom
   auto sceneRect=controlledObject->scene()->sceneRect();
   auto ballRect=controlledObject->boundingRect();
   ballRect=controlledObject->mapRectToScene(ballRect);
   auto ballDirection=controlledObject->getDirection();
   if(ballRect.top()<=sceneRect.top())
   {
       ballDirection.setY(ballDirection.y()<0?-ballDirection.y():ballDirection.y());
   }
   if(ballRect.bottom()>=sceneRect.bottom())
   {
        ballDirection.setY(ballDirection.y()<0?ballDirection.y():-ballDirection.y());
   }
   //checks if ball hit paddle
   auto scene=controlledObject->scene();
   auto items=scene->collidingItems(controlledObject.get());
   if(!items.empty())
   {
       //This code solves multireflections
       auto currTime=QTime::currentTime();
       if(currTime.msecsSinceStartOfDay()-lastMeasuredTime.msecsSinceStartOfDay()>colisionDelay)
       {
            auto paddle=static_cast<GameObject*>(items[0]);
            auto paddleHeight=paddle->getHeight();
            auto paddlePos=paddle->pos();
            paddlePos=paddle->mapToScene(paddlePos);
            auto ballPos=controlledObject->pos();
            ballPos=controlledObject->mapToScene(ballPos);
            auto ballHeight=controlledObject->getHeight();
            auto part=paddleHeight/ballHeight;
            auto posDiff=qAbs(paddlePos.y()-ballPos.y());
            auto whichPart=int(posDiff/ballHeight);
            switch(whichPart)
            {
            case 1:
                if(ballDirection.y()>0)
                ballDirection.setY(-ballDirection.y());
                ballDirection.setY(ballDirection.y()/1.2);
            case 0:
                if(ballDirection.y()>0)
                ballDirection.setY(-ballDirection.y());
                ballDirection.setY(ballDirection.y()*1.2);
                break;
            case 2:
                if(ballDirection.y()<0)
                ballDirection.setY(-ballDirection.y());
                ballDirection.setY(ballDirection.y()/1.2);
                break;
            case 3:
                if(ballDirection.y()<0)
                ballDirection.setY(-ballDirection.y());
                ballDirection.setY(ballDirection.y()*1.2);
                break;
            default:
            break;
            }
            ballDirection.setX(-ballDirection.x());

       }
        lastMeasuredTime=QTime::currentTime();
   }

   auto ball=static_cast<Ball*>(controlledObject.get());
   ball->setDirection(ballDirection);
   controlledObject->move(ballDirection);
   //emit signals if ball left scene
   if(ballRect.left()>=sceneRect.right())
   {
        emit ballLeftScene(true);
   }
   if(ballRect.right()<=sceneRect.left())
   {
      emit ballLeftScene(false);
   }
   //speed up ball to make game more fun
   if(QTime::currentTime().msecsSinceStartOfDay()-timeToSpeedUp.msecsSinceStartOfDay()>5000)
   {
       if(ball->getSpeed()<7)
        ball->setSpeed(ball->getSpeed()+0.5);
        timeToSpeedUp=QTime::currentTime();
   }

}
