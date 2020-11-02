#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QTimer>

#include "pensil.h"

class DrawArea : public QGraphicsScene
{
    Q_OBJECT
public:
    DrawArea(QObject* parent = 0);

private:
    bool buttonPressed;
    QTimer* timer;
   // Pensil* pensil;
    QMouseEvent* mouseEv;
    // QGraphicsScene interface
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

public slots:
    void updateDraw(QPointF);
    void mouseMoveEv(QMouseEvent *event);
};

#endif // DRAWAREA_H
