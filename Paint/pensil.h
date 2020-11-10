#ifndef PENSIL_H
#define PENSIL_H

#include <QPainter>
#include <QDebug>

class Pensil
{
private:
    int mRadius;
    QPen mPen;
public:
    Pensil(int radius = 2);

    void setBrushWidth(int radius) { qDebug() << radius; mRadius = radius; }
    QPen getPen() { return mPen; }
};

#endif // PENSIL_H
