#include "drawarea.h"

#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include <QApplication>
#include <QWidget>

DrawArea::DrawArea(QObject *parent) : QGraphicsScene(parent), drawing(false), mPensil{}
{
    mPensil = new Pensil();

   // connect(this, &DrawArea::mousePress, [=](){ setState(State::Press); eventState = State::Press; });
   // connect(this, &DrawArea::mouseMove, [=](){ setState(State::Move); eventState = State::Move; });
   // connect(this, &DrawArea::setState, [=](){ mPensil->updateState(State::Press); });
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
