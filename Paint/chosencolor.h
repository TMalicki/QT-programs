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
    void setHighlightBackground() {
        this->setStyleSheet(".chosenColor{ background-color: rgba(186, 227, 255,0.4); border: 1px solid rgba(102, 160, 255, 1.0);}");}
    void resetHighlightBackground() {
        this->setStyleSheet(".chosenColor{ background-color: transparent; border: none}");}
signals:
    void click();

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

    // QWidget interface
protected:
    virtual void mousePressEvent(QMouseEvent *event);
};

#endif // CHOSENCOLOR_H
