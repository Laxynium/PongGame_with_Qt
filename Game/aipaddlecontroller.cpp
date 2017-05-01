#include "aipaddlecontroller.h"
#include <QDebug>
#include <QGraphicsScene>
#include <Game/ball.h>
AIPaddleController::AIPaddleController(QObject *parent): GameObjectController(parent)
{
}

Ball* AIPaddleController::findBall()
{
    auto objects=controlledObject->scene()->items();
    Ball*ball;
    for(auto&obj:objects)
    {
        ball=dynamic_cast<Ball*>(obj);
        if(ball)
            break;
    }
    return ball;
}

void AIPaddleController::Tick()
{
    if(!controlledObject)
    {
        qDebug()<<"ControlledObject isn't set\n";
        return ;
    }
    auto ball=findBall();
    if(!ball)
    {
        qDebug()<<"Ball not found\n";
        return;
    }

    //get ball and paddle center
    auto ballPos=ball->boundingRect();
    auto ballCenter=ballPos.center();

    auto objectRect=controlledObject->boundingRect();
    auto paddleCenter=objectRect.center();

    //controlledObject->setPos(controlledObject->pos().x(),ballCenter.y()-50);
    //follow ball by paddle
    if(ball->getBallDirection().x()>0&&ball->pos().x()>120)//Here you can controll how fast is paddle
    {
        if(abs(paddleCenter.y()-ballCenter.y())>controlledObject->getSpeed().y())
        {
            if(paddleCenter.y()>ballCenter.y())
            {
                controlledObject->move(QVector2D(0,-1));

            }else if(paddleCenter.y()<ballCenter.y())
            {
               controlledObject->move(QVector2D(0,1));
            }
        }
    }

}

void AIPaddleController::setControlledObject(std::shared_ptr<GameObject> newControlledObject)
{
    controlledObject=newControlledObject;
}

std::shared_ptr<GameObject> AIPaddleController::getControlledObject()
{
    return controlledObject;
}
