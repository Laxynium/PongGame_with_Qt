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
    connect(gameLoopTimer,&QTimer::timeout,this,&Game::gameLoop);
    connect(static_cast<BallBehaviour*>(controllers[2].get()),&BallBehaviour::ballLeftScene,
            [this](bool onRightSite){(onRightSite?scoreBoard->addPoints(true):scoreBoard->addPoints(false));
    restartItemsPosition();});
    connect(scoreBoard,&ScoreBoard::someoneWon,this,&Game::someOneWon);
    gameLoopTimer->setInterval(20);
    mView->scale(2.0,2.0);
}

void Game::InitialiseGame()
{
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

    //Set postions
    restartItemsPosition();
}
void Game::restartItemsPosition()
{
    gameObjects[0]->setPos(145,100);
    gameObjects[1]->setPos(0,100);
    gameObjects[2]->setPos(310,100);
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
    //TODO emit gameEnded signal
    //and connect it with gameover screen
    if(isPlayer)
    {
        qDebug()<<"Player won\n";
    }
    else
    {
        qDebug()<<"AI won\n";
    }
    scoreBoard->restartPoints();
    stopGame();
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



