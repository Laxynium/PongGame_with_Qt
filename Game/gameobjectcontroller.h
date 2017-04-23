#ifndef GAMEOBJECTCONTROLLER_H
#define GAMEOBJECTCONTROLLER_H

#include <QObject>

class GameObjectController : public QObject
{
    Q_OBJECT
public:
    explicit GameObjectController(QObject *parent = 0);

signals:

public slots:
};

#endif // GAMEOBJECTCONTROLLER_H