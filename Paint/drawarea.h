#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>

#include "pensil.h"

class DrawArea : public QGraphicsScene
{
    Q_OBJECT
public:
    DrawArea(QObject* parent = 0);

private:
    bool drawing;
    qreal mRadius;
    QPainterPath mDrawPath;
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // DRAWAREA_H
