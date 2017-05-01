#ifndef BALLBEHAVIOUR_H
#define BALLBEHAVIOUR_H

#include "Game/gameobjectcontroller.h"
#include <QTime>
class BallBehaviour:public GameObjectController
{
    Q_OBJECT
public:
    BallBehaviour(QObject*parent=nullptr);
public:
    virtual void setControlledObject(std::shared_ptr<GameObject> newControlledObject) override;
    virtual std::shared_ptr<GameObject> getControlledObject() override;
public slots:
    virtual void Tick() override;
signals:
    void ballLeftScene(bool onRightSite);
private:
    std::shared_ptr<GameObject>controlledObject;
    QVector2D ballDirection{-4,2};
    qreal colisionDeley=200;
    QTime lastTime;
};

#endif // BALLBEHAVIOUR_H
