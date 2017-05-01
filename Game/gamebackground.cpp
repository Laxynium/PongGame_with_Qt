#include "gamebackground.h"

GameBackground::GameBackground(QGraphicsItem *parent):QGraphicsRectItem(parent)
{

}

bool GameBackground::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    return false;
}

bool GameBackground::collidesWithPath(const QPainterPath &path, Qt::ItemSelectionMode mode) const
{
    return false;
}

QPainterPath GameBackground::shape() const
{
    return QPainterPath();
}
