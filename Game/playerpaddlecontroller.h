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

    void setKeyToMoveUp(Qt::Key up);
    void setKeyToMoveDown(Qt::Key down);
public:
    virtual bool event(QEvent *event) override;
public slots:
    virtual void Tick() override;
private:
    std::shared_ptr<GameObject>controlledObject;

    //Variables used to move paddle
    //they should be in other class
    class QTimer*timerHelpingWtihMovement;
    int reversal=1;
    Qt::Key keyToMoveUp=Qt::Key_W;
    Qt::Key keyToMoveDown=Qt::Key_S;
    // QObject interface

};

#endif // PLAYERPADDLECONTROLLER_H
