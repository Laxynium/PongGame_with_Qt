#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QGraphicsTextItem>

class ScoreBoard:public QGraphicsTextItem
{
    Q_OBJECT
public:
    ScoreBoard(QGraphicsItem *parent = nullptr);
public slots:
    void addPoints(bool toPlayer);
    void restartPoints();
signals:
    void someoneWon(bool isPlayer);
private:
    int player_points=0;
    int AI_points=0;
    const int score_to_Win=10;
private:
    void updateText();
    // QGraphicsItem interface
public:
    virtual QPainterPath shape() const override;
};

#endif // SCOREBOARD_H
