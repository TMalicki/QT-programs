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
signals:

private:
    QVBoxLayout* layout;
    QLabel* colorBox;
    QLabel* text;
    static int counter;

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event);
};

#endif // CHOSENCOLOR_H
