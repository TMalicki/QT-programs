#include "pensil.h"

Pensil::Pensil(int radius) : mRadius{radius}, mPen{}
{
    mPen.setWidth(mRadius);
    mPen.setColor(Qt::red);
    mPen.setStyle(Qt::SolidLine);
}
