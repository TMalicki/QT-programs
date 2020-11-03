#include "drawarea.h"

#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include <QApplication>

DrawArea::DrawArea(QObject *parent) : QGraphicsScene(parent), drawing(false), mRadius(2), mDrawPath{}
{}

void DrawArea::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() & Qt::LeftButton)
    {
        mDrawPath.moveTo(event->scenePos());

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
        mDrawPath.lineTo(event->scenePos());

        this->clear();
        addPath(mDrawPath);
    }
}



