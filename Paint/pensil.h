#ifndef PENSIL_H
#define PENSIL_H

#include <QPainter>
#include <QDebug>

class Pensil
{
private:
    QPen mPen;
public:
    Pensil(int radius = 2);

    void setBrushWidth(int radius) { mPen.setWidth(radius); }
    const QPen getPen() { return mPen; }
};

#endif // PENSIL_H
