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
public:
    explicit Game(QObject *parent = 0);
    QGraphicsView *getView()const;
    // QObject interface
    virtual bool event(QEvent *event) override;

public slots:
    void startGame();
    void restartGame();
    void resizeGame(double w_scale,double h_scale);

    void setKeyToMoveUp(Qt::Key up);
    void setKeyToMoveDown(Qt::Key down);

signals:
    void gameStopped();
    void gameEnded(bool playerWon);//TODO replace bool with enum

private slots:
    bool isGameRunning()const;
    void gameLoop();
    void stopGame();

    void someoneWon(bool isPlayer);
    void someoneScored(bool isPlayer);
private:
    void InitialiseGame();
    void restartItemsPosition();
    QVector2D randomDirection();

private:
std::vector<std::unique_ptr<GameObjectController>>controllers;
std::vector<std::shared_ptr<GameObject>>gameObjects;

GameScene*mScene=nullptr;
QGraphicsView*mView=nullptr;
ScoreBoard*scoreBoard=nullptr;

QTimer*gameLoopTimer=nullptr;

bool isRunning=false;


};

#endif // GAME_H
