#include "pensil.h"

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QPainter>
#include <QDebug>

Pensil::Pensil(qreal radius) : radius(radius)
{

}

void Pensil::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    pen.setCosmetic(true);
    painter->setPen(pen);

  //  painter->drawEllipse(actualPoint, radius, radius);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Pensil::boundingRect() const
{
    return QRectF();
}

