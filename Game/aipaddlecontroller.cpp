#include "aipaddlecontroller.h"
#include <QDebug>
#include <QGraphicsScene>
AIPaddleController::AIPaddleController(QObject *parent): GameObjectController(parent)
{

}

void AIPaddleController::Tick()
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

void AIPaddleController::setControlledObject(std::shared_ptr<GameObject> newControlledObject)
{
    controlledObject=newControlledObject;
}

std::shared_ptr<GameObject> AIPaddleController::getControlledObject()
{
    return controlledObject;
}
