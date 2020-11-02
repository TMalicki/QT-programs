#ifndef PENSIL_H
#define PENSIL_H

#include <QGraphicsItem>
#include <QGraphicsScene>

class Pensil : public QGraphicsItem
{
public:
    Pensil(qreal radius = 2);

    // QGraphicsItem interface
public:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual QRectF boundingRect() const;



private:
    qreal radius;
    
};

#endif // PENSIL_H
