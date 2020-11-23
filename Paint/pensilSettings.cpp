#include "pensilSettings.h"

pensilSettings::pensilSettings(int radius) : mPen{}
{
    mPen.setWidth(radius);
    mPen.setColor(Qt::black);
    mPen.setStyle(Qt::SolidLine);
    mPen.setCapStyle(Qt::RoundCap);
}
