#ifndef PLAYERPADDLECONTROLLER_H
#define PLAYERPADDLECONTROLLER_H

#include <Game/gameobjectcontroller.h>

class PlayerPaddleController:public GameObjectController
{
    Q_OBJECT
public:
    PlayerPaddleController(QObject*parent=nullptr,std::shared_ptr<GameObject> newControlledObject=nullptr);
    void setControlledObject(std::shared_ptr<GameObject> newControlledObject);
     virtual std::shared_ptr<GameObject> getControlledObject();
public slots:
    virtual void Tick() override;
private:
    int rev=1;
    std::shared_ptr<GameObject>controlledObject;

    // QObject interface
public:
    virtual bool event(QEvent *event) override;
};

#endif // PLAYERPADDLECONTROLLER_H
