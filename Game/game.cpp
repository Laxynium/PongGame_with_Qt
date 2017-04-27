#include "game.h"
#include <QEvent>
#include <Game/aipaddlecontroller.h>
#include <Game/playerpaddlecontroller.h>
#include <Game/ball.h>
#include <Game/paddle.h>
#include <QGraphicsItem>
#include <QTimer>
#include "Game/gamescene.h"
#include <QDebug>
#include <QCoreApplication>
Game::Game(QObject *parent) : QObject(parent),
    mScene(new GameScene(this)),mView(new QGraphicsView()),
    gameTimer(new QTimer(this))
{
    mScene->setSceneRect(0,0,640,480);
    mView->setScene(mScene);
    mScene->setBackgroundBrush(Qt::gray);
    mView->setMinimumSize(640,480);
    mView->setAlignment(Qt::AlignHCenter);
    mView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    InitialiseGame();
    //for(auto &el:controllers)
    {
        connect(gameTimer,&QTimer::timeout,controllers[1].get(),&GameObjectController::Tick);
    }
    //connect(gameTimer,&QTimer::timeout,[this](){gameObjects[0]->move({2,0});});//connect Ball
    gameTimer->start(15);
   // gameTimer->singleShot(2000,Qt::TimerType(),this,&Game::SwapControllers); //Just  test of capabilities of Controllers
}

QGraphicsView* Game::getView() const
{
    return mView;
}

void Game::SwapControllers()
{
    auto gameObject=controllers[0]->getControlledObject();
    controllers[0]->setControlledObject(controllers[1]->getControlledObject());
    controllers[1]->setControlledObject(gameObject);
}

void Game::InitialiseGame()
{
    //Create Controllers;
    auto PlayerController=std::make_unique<PlayerPaddleController>();
    auto AIController=std::make_unique<AIPaddleController>();

    //Create Objects
    auto ball=std::make_shared<Ball>();
    auto Player_Paddle=std::make_shared<Paddle>();
    auto AI_Paddle=std::make_shared<Paddle>();

    //Set postions
    ball->setPos(145,100);
    Player_Paddle->setPos(0,100);
    AI_Paddle->setPos(290,100);
    //connect Controllers with Objects
    PlayerController->setControlledObject(Player_Paddle);
    AIController->setControlledObject(AI_Paddle);

    //Store Controllers
    controllers.push_back(std::move(PlayerController));
    controllers.push_back(std::move(AIController));
    //Store game Objects
    gameObjects.push_back(ball);
    gameObjects.push_back(Player_Paddle);
    gameObjects.push_back(AI_Paddle);
    //Add game Objects to Scene
    mScene->addItem(ball.get());
    mScene->addItem(Player_Paddle.get());
    mScene->addItem(AI_Paddle.get());
}

bool Game::event(QEvent *event)
{
    for(auto&el:controllers)
    {
        QCoreApplication::sendEvent(el.get(),event);
    }
    return true;
}
