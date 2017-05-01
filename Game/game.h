#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <vector>
#include <memory>
#include "Game/gameobjectcontroller.h"
class GameScene;
class QTimer;
class ScoreBoard;
class Game : public QObject
{
    Q_OBJECT
    // QObject interface
public:
    virtual bool event(QEvent *event) override;
public:
    explicit Game(QObject *parent = 0);
    QGraphicsView *getView()const;
public slots:
    void startGame();
    void stopGame();
    bool isGameRunning()const;
    void restartGame();

signals:
    void gameStopped();
    void gameEnded(bool playerWon);
private slots:
    void SwapControllers();
    void gameLoop();
    void someOneWon(bool isPlayer);
private:
    void InitialiseGame();
    void restartItemsPosition();
private:
std::vector<std::unique_ptr<GameObjectController>>controllers;
std::vector<std::shared_ptr<GameObject>>gameObjects;
GameScene*mScene;
QGraphicsView*mView;
ScoreBoard*scoreBoard;
QTimer*gameLoopTimer=nullptr;
bool isRunning=false;


};

#endif // GAME_H
