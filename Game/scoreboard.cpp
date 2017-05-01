#include "scoreboard.h"
#include <QString>
#include <QDebug>
ScoreBoard::ScoreBoard(QGraphicsItem *parent):QGraphicsTextItem(parent)
{

}

void ScoreBoard::addPoints(bool toPlayer)
{
    if(toPlayer)
        player_points++;
    else
    {
        AI_points++;
    }
    updateText();
    if(player_points==score_to_Win)
        emit someoneWon(true);
    else if(AI_points==score_to_Win)
        emit someoneWon(false);
}

void ScoreBoard::restartPoints()
{
    player_points=0;
    AI_points=0;
    updateText();
}

void ScoreBoard::updateText()
{
    auto p_p=QString::number(player_points,10);
    auto ai_p=QString::number(AI_points,10);
    QString text="<html><head/><body><p align='center'><span style=' font-size:50pt; color:#55aaff;'>";
    text+=p_p+" : "+ai_p;
    text+="</span></p></body></html>";
    setHtml(text);
}

QPainterPath ScoreBoard::shape() const
{
    return QPainterPath();
}
