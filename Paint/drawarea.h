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

public:
    void setBrushSize(int brushSize) { mPensil->setBrushWidth(brushSize); }

private:
    QPointF previousPoint;
    bool drawing;
    Pensil* mPensil;

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // DRAWAREA_H
