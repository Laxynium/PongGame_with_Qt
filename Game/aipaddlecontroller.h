#ifndef AIPADDLECONTROLLER_H
#define AIPADDLECONTROLLER_H

#include <Game/gameobjectcontroller.h>

class AIPaddleController:public GameObjectController
{
    Q_OBJECT
public:
    AIPaddleController(QObject*parent=nullptr);
    void setControlledObject(std::shared_ptr<GameObject> newControlledObject=nullptr);
    virtual std::shared_ptr<GameObject> getControlledObject();
public slots:
    virtual void Tick() override;
private:
    int rev=1;
    std::shared_ptr<GameObject>controlledObject;
};

#endif // AIPADDLECONTROLLER_H
