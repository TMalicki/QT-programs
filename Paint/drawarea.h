#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QVector>

#include "pensilSettings.h"

class DrawArea : public QGraphicsScene
{
    Q_OBJECT
public:
    DrawArea(QObject* parent = 0);

public:
    void setBrushSize(int brushSize) { mPensil->setBrushWidth(brushSize); }
    void checkShortcuts();
    void setColor(QColor color) { mPensil->setColor(color); }
private:
    QPointF previousPoint;
    bool drawing;
    pensilSettings* mPensil;
    QVector<int> pressedKeys;

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    // QGraphicsScene interface
protected:
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);
};

#endif // DRAWAREA_H
