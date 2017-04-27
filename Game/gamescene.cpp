#include "gamescene.h"
#include <QKeyEvent>
#include <QCoreApplication>
GameScene::GameScene(QObject *parent) : QGraphicsScene(parent)
{

}

void GameScene::keyPressEvent(QKeyEvent *event)
{
    QCoreApplication::sendEvent(parent(),event);
    QGraphicsScene::keyPressEvent(event);
}

void GameScene::keyReleaseEvent(QKeyEvent *event)
{
     QCoreApplication::sendEvent(parent(),event);
     QGraphicsScene::keyReleaseEvent(event);
}
