#include "chosencolor.h"
#include <QDebug>
#include <QPainter>
#include <QStyleOption>

int chosenColor::counter{0};

chosenColor::chosenColor(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout(this);

    colorBox = new QLabel("");
    colorBox->setAlignment(Qt::AlignCenter);
    colorBox->setStyleSheet("*{background-color:red; border: 1px solid black; }");
    //colorBox->setFixedSize(30,30);

    text = new QLabel("Color 1");
    text->setWordWrap(true);
    text->setAlignment(Qt::AlignCenter);
    text->setStyleSheet("background-color:transparent;");

    layout->addWidget(colorBox, Qt::AlignCenter);
    layout->addWidget(text, Qt::AlignCenter);

    this->setLayout(layout);

    counter++;
    setSize();
}

void chosenColor::setSize()
{
    if(counter == 1)
    {
        this->setFixedSize(50,80);
    }
    else
    {
        this->setFixedSize(50,80);
        //colorBox->setFixedSize(colorBox->size() - QSize(5,5));
    }
}

void chosenColor::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}
