#ifndef CHOSENCOLOR_H
#define CHOSENCOLOR_H

#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QWidget>

class chosenColor : public QWidget
{
    Q_OBJECT
public:
    explicit chosenColor(QWidget *parent = nullptr);
signals:

private:
    QVBoxLayout* layout;
    QLineEdit* colorBox;
    QLabel* text;
};

#endif // CHOSENCOLOR_H
