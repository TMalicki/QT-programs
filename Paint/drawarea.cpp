#include "drawarea.h"

#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include <QApplication>


DrawArea::DrawArea(QObject *parent) : QGraphicsScene(parent), buttonPressed(false)
{
    //mouseEv = new QMouseEvent(QEvent::MouseMove,QPointF(qreal(0),qreal(0)),Qt::MouseButton::NoButton);
    timer = new QTimer(this);
    timer->setInterval(60);
    //connect(timer, &QTimer::timeout, [=](){ updateDraw(); });
}

void DrawArea::updateDraw(QPointF mousePos)
{
    mouseEv = new QMouseEvent(QEvent::MouseMove, mousePos, Qt::NoButton, Qt::LeftButton, Qt::NoModifier);
    mouseMoveEv(mouseEv);
}

void DrawArea::mouseMoveEv(QMouseEvent *event)
{
    QPointF pos = event->pos();
    qDebug() << pos;
    auto radius = qreal(2);

    auto* ellipse = this->addEllipse(QRect(pos.x()-radius, pos.y()-radius, 2*radius, 2*radius));
    ellipse->setBrush(QBrush(QColor(Qt::black),Qt::SolidPattern));

    event->accept();
}


void DrawArea::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() & Qt::LeftButton)
    {
        QPointF pos = event->scenePos();

        auto radius = qreal(2);

        auto* ellipse = this->addEllipse(QRect(pos.x()-radius, pos.y()-radius, 2*radius, 2*radius));
        ellipse->setBrush(QBrush(QColor(Qt::black),Qt::SolidPattern));
        buttonPressed = true;

        connect(timer, &QTimer::timeout, [=](){ updateDraw(event->scenePos()); });
        timer->start();

     //   event->accept();
    }
    else event->ignore();
}

void DrawArea::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() & Qt::LeftButton)
    {
        buttonPressed = false;
        qDebug() << "RELEASED";
        timer->stop();
    }
}

void DrawArea::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /*
    if(buttonPressed == false){}
    else
    {
        QPointF pos = event->scenePos();

        auto radius = qreal(2);

        auto* ellipse = this->addEllipse(QRect(pos.x()-radius, pos.y()-radius, 2*radius, 2*radius));
        ellipse->setBrush(QBrush(QColor(Qt::black),Qt::SolidPattern));
    }

    if()
    */
}



