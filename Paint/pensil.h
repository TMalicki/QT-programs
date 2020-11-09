#ifndef PENSIL_H
#define PENSIL_H

#include <QPainter>



class Pensil
{
private:
    qreal mRadius;
    QPen mPen;
public:
    Pensil(qreal radius = 2.0f);

    QPen getPen() { return mPen; }
};

#endif // PENSIL_H
