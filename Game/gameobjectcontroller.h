#ifndef GAMEOBJECTCONTROLLER_H
#define GAMEOBJECTCONTROLLER_H

#include <QObject>
#include <memory>
#include <Game/gameobject.h>
class GameObjectController : public QObject
{
    Q_OBJECT
public:
    explicit GameObjectController(QObject *parent = 0);
    virtual void setControlledObject(std::shared_ptr<GameObject>newControlledObject)=0;
    virtual std::shared_ptr<GameObject> getControlledObject()=0;
public slots:
    virtual void Tick()=0;
signals:

};

#endif // GAMEOBJECTCONTROLLER_H
