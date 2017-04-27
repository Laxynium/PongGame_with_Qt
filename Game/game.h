#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <vector>
#include <memory>
#include "Game/gameobjectcontroller.h"

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = 0);
    QGraphicsView *getView()const;
signals:
public slots:
private slots:
    void SwapControllers();
private:
    void InitialiseGame();
private:
std::vector<std::unique_ptr<GameObjectController>>controllers;
std::vector<std::shared_ptr<GameObject>>gameObjects;
class GameScene*mScene;
QGraphicsView*mView;
class QTimer*gameTimer=nullptr;

// QObject interface
public:
virtual bool event(QEvent *event) override;
};

#endif // GAME_H
