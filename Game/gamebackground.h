#ifndef GAMEBACKGROUND_H
#define GAMEBACKGROUND_H

#include <QGraphicsRectItem>

class GameBackground:public QGraphicsRectItem
{
public:
    GameBackground(QGraphicsItem *parent=nullptr);

    // QGraphicsItem interface
public:
    //The aim of overriding that methods is to disable colision with that itmes
    virtual bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    virtual bool collidesWithPath(const QPainterPath &path, Qt::ItemSelectionMode mode) const override;

    // QGraphicsItem interface
public:
    virtual QPainterPath shape() const override;
};

#endif // GAMEBACKGROUND_H
