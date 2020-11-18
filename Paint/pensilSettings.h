#ifndef PENSIL_H
#define PENSIL_H

#include <QPainter>
#include <QDebug>

class pensilSettings
{
private:
    QPen mPen;
public:
    pensilSettings(int radius = 2);

    void setBrushWidth(int radius) { mPen.setWidth(radius); }
    void setColor(QColor color) { mPen.setColor(color); }
    const QPen getPen() { return mPen; }
};

#endif // PENSIL_H
