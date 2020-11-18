#include "drawarea.h"

#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include <QApplication>
#include <QWidget>

DrawArea::DrawArea(QObject *parent) : QGraphicsScene(parent), drawing(false), mPensil{}, pressedKeys{}
{
    mPensil = new pensilSettings();
}

void DrawArea::checkShortcuts()
{
    if(pressedKeys.size() == 2)
    {
        if((pressedKeys[0] == Qt::Key_Plus && pressedKeys[1] == Qt::Key_Control)
           || (pressedKeys[0] == Qt::Key_Control && pressedKeys[1] == Qt::Key_Plus))
        {
            mPensil->setBrushWidth(mPensil->getPen().width() + 1);
        }
        else if((pressedKeys[0] == Qt::Key_Minus && pressedKeys[1] == Qt::Key_Control)
           || (pressedKeys[0] == Qt::Key_Control && pressedKeys[1] == Qt::Key_Minus))
        {
            mPensil->setBrushWidth(mPensil->getPen().width() - 1);
        }
    }
}

void DrawArea::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() & Qt::LeftButton)
    {
        previousPoint = event->scenePos();

        event->accept();
        drawing = true;
    }
    else event->ignore();
}

void DrawArea::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() & Qt::LeftButton)
    {
        drawing = false;
    }
}

void DrawArea::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{ 
    if(drawing == false) {}
    else
    {
         addLine(previousPoint.x(),
                 previousPoint.y(),
                 event->scenePos().x(),
                 event->scenePos().y(), mPensil->getPen());
         previousPoint = event->scenePos();
    }
}

void DrawArea::keyPressEvent(QKeyEvent *event)
{
    bool notPressed {true};

    if(pressedKeys.size() == 0) pressedKeys.push_back(event->key());
    for(auto& key : pressedKeys)
    {
        if(key == event->key()) notPressed = false;
    }
    if(notPressed == true) pressedKeys.push_back(event->key());

    checkShortcuts();
}

void DrawArea::keyReleaseEvent(QKeyEvent *event)
{
    pressedKeys.erase(std::remove(pressedKeys.begin(), pressedKeys.end(), event->key()), pressedKeys.end());
}
