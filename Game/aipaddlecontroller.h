#ifndef AIPADDLECONTROLLER_H
#define AIPADDLECONTROLLER_H

#include <Game/gameobjectcontroller.h>
class Ball;
class AIPaddleController:public GameObjectController
{
    Q_OBJECT
public:
    AIPaddleController(QObject*parent=nullptr);
    virtual void setControlledObject(std::shared_ptr<GameObject> newControlledObject=nullptr)override;
    virtual std::shared_ptr<GameObject> getControlledObject()override;
public slots:
    virtual void Tick() override;
private:
    int rev=1;
    std::shared_ptr<GameObject>controlledObject;
    Ball*findBall();
};

#endif // AIPADDLECONTROLLER_H
