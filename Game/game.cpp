#include "game.h"
#include <QEvent>
#include <Game/aipaddlecontroller.h>
#include <Game/playerpaddlecontroller.h>
#include "Game/ballbehaviour.h"
#include <Game/ball.h>
#include <Game/paddle.h>
#include "Game/gamebackground.h"
#include <QGraphicsItem>
#include <QTimer>
#include "Game/gamescene.h"
#include <QDebug>
#include <QCoreApplication>
#include <QKeyEvent>
#include <Game/scoreboard.h>
#include <QResizeEvent>
#include <QSize>
#include <random>
#include <algorithm>
//TODO make clear logic and names of function
//resposible for game ending/ game pausing/ game restarting
Game::Game(QObject *parent) : QObject(parent),
    mScene(new GameScene(this)),mView(new QGraphicsView()),
    gameLoopTimer(new QTimer(this))
{
    //Initialise scene and scenView
    mScene->setSceneRect(0,0,640,480);
    mView->setScene(mScene);
    mView->setMinimumSize(640,480);
    mView->setAlignment(Qt::AlignHCenter);
    mView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mView->setBackgroundBrush(Qt::gray);

    InitialiseGame();
    //connect actions
    // main loop
    connect(gameLoopTimer,&QTimer::timeout,this,&Game::gameLoop);
    //when someone scored
    connect(static_cast<BallBehaviour*>(controllers[2].get()),&BallBehaviour::ballLeftScene,this,&Game::someOneScored);
    //when someone won
    connect(scoreBoard,&ScoreBoard::someoneWon,this,&Game::someOneWon);

    gameLoopTimer->setInterval(20);
}

void Game::InitialiseGame()
{
    //todo extract to functions
    //Create Controllers;
    auto PlayerController=std::make_unique<PlayerPaddleController>();
    auto AIController=std::make_unique<AIPaddleController>();
    auto ballBehaviour=std::make_unique<BallBehaviour>();
    //Create Objects
    auto ball=std::make_shared<Ball>();
    auto Player_Paddle=std::make_shared<Paddle>();
    auto AI_Paddle=std::make_shared<Paddle>();
    //connect Controllers with Objects
    PlayerController->setControlledObject(Player_Paddle);
    AIController->setControlledObject(AI_Paddle);
    ballBehaviour->setControlledObject(ball);

    //Store Controllers
    controllers.push_back(std::move(PlayerController));
    controllers.push_back(std::move(AIController));
    controllers.push_back(std::move(ballBehaviour));
    //Store game Objects
    gameObjects.push_back(ball);
    gameObjects.push_back(Player_Paddle);
    gameObjects.push_back(AI_Paddle);
    //Add game Objects to Scene
    //add background
    auto background=new GameBackground();
    background->setBrush(Qt::green);
    background->setRect(0,0,640,480);
    mScene->addItem(background);
    //Add scoreboard
    scoreBoard=new ScoreBoard();
    scoreBoard->setPos(250,100);
    scoreBoard->setZValue(100);
    mScene->addItem(scoreBoard);
    //Add rest items
    mScene->addItem(ball.get());
    mScene->addItem(Player_Paddle.get());
    mScene->addItem(AI_Paddle.get());

    //Set default positions
    gameObjects[0]->setDefaultPosition({145,100});
    gameObjects[1]->setDefaultPosition({0,100});
    gameObjects[2]->setDefaultPosition({310,100});

    //Set postions
    restartItemsPosition();
    //Set key to Move

}
void Game::restartItemsPosition()
{
    //think where restaring position should be placed
    for(auto&object:gameObjects)
    {
        object->setPos(object->getDefaultPosition());
    }
}

QVector2D Game::randomDirection()
{
    std::random_device device;
    std::mt19937 engin(device());
    std::uniform_int_distribution<int>Xdistr(30,50);
    std::uniform_int_distribution<int>Ydistr(10,29);
    float x=Xdistr(engin);
    float y=Ydistr(engin);
    if(y>x)std::swap(x,y);
    return {x,y};
}

void Game::gameLoop()
{
    for(auto&controller:controllers)
    {
        controller->Tick();
    }
}

bool Game::event(QEvent *event)
{
    if(event->type()==QEvent::Type::KeyPress)
    {
        auto keyPress=static_cast<QKeyEvent*>(event);
        if(keyPress->key()==Qt::Key_Escape)
        {
            stopGame();
        }
    }
    if(isGameRunning())
    {
        for(auto&el:controllers)
        {
            QCoreApplication::sendEvent(el.get(),event);
        }
    }
    //return is unused
    return true;
}


QGraphicsView* Game::getView() const
{
    return mView;
}

void Game::restartGame()
{
    restartItemsPosition();
    scoreBoard->restartPoints();
    startGame();
}

void Game::resizeGame(double w_scale, double h_scale)
{
    mView->scale(w_scale,h_scale);
}

void Game::setKeyToMoveUp(Qt::Key up)
{
    if(!controllers.empty())
    {
        auto PlayerController=dynamic_cast<PlayerPaddleController*>(controllers[0].get());
        if(PlayerController)
        PlayerController->setKeyToMoveUp(up);
    }
}

void Game::setKeyToMoveDown(Qt::Key down)
{
    if(!controllers.empty())
    {
        auto PlayerController=dynamic_cast<PlayerPaddleController*>(controllers[0].get());
        if(PlayerController)
        PlayerController->setKeyToMoveDown(down);
    }

}

void Game::startGame()
{
    isRunning=true;
    gameLoopTimer->start();
}

void Game::stopGame()
{
    isRunning=false;
    gameLoopTimer->stop();
    emit gameStopped();
}
void Game::someOneWon(bool isPlayer)
{
    scoreBoard->restartPoints();
    isRunning=false;
    gameLoopTimer->stop();
    emit gameEnded(isPlayer);
}

void Game::someOneScored(bool isPlayer)
{
    isPlayer?scoreBoard->addPoints(true):scoreBoard->addPoints(false);
    restartItemsPosition();
    for(auto&el:gameObjects)
    {
        el->init();
    }
    auto dir=randomDirection();
    dir.setX(-dir.x());
    gameObjects[0]->setDirection(dir);
}

bool Game::isGameRunning() const
{
    return isRunning;
}

void Game::SwapControllers()
{
    auto gameObject=controllers[0]->getControlledObject();
    controllers[0]->setControlledObject(controllers[1]->getControlledObject());
    controllers[1]->setControlledObject(gameObject);
}



