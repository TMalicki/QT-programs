#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QPainter>

#include "pensil.h"

//enum State { Press, Move };

class DrawArea : public QGraphicsScene
{
    Q_OBJECT
public:
    DrawArea(QObject* parent = 0);

private:
    QPointF previousPoint;

    bool drawing;
    //qreal mRadius;
    //QPainter* mPainter;
    //QPainterPath mDrawPath;
    Pensil* mPensil;//
    //int eventState;

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

signals:
   // void mousePress();
   // void mouseMove();
   // void setState(State state);
};

#endif // DRAWAREA_H
