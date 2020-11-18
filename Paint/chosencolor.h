#ifndef CHOSENCOLOR_H
#define CHOSENCOLOR_H

#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

class chosenColor : public QWidget
{
    Q_OBJECT
public:
    explicit chosenColor(QWidget *parent = nullptr);
    void setSize();
    QColor getColor() { return color; }
signals:

private:
    QVBoxLayout* layout;
    QVBoxLayout* frameLayout;
    QFrame* frame;
    QLabel* colorBox;
    QLabel* text;
    static int counter;
    QColor color;

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event);
};

#endif // CHOSENCOLOR_H
