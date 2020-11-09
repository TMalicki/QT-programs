#include "pensil.h"

Pensil::Pensil(qreal radius) : mRadius{radius}, mPen{}
{
    mPen.setWidth(mRadius);
    mPen.setColor(Qt::red);
    mPen.setStyle(Qt::SolidLine);
}
