#include "chosencolor.h"
#include <QDebug>
#include <QPainter>
#include <QStyleOption>

int chosenColor::counter{0};

chosenColor::chosenColor(QWidget *parent) : QWidget(parent), color{QColor(Qt::black)}
{
    layout = new QVBoxLayout(this);

    colorBox = new QLabel("");
    colorBox->setAlignment(Qt::AlignCenter);
    colorBox->setStyleSheet("*{background-color:red; border: 1px solid black; }");

    text = new QLabel("");
    text->setWordWrap(true);
    text->setAlignment(Qt::AlignCenter);
    text->setStyleSheet("background-color:transparent;");

    frame = new QFrame;
    frameLayout = new QVBoxLayout;
    frameLayout->addWidget(colorBox);
    frameLayout->setMargin(1);
    frame->setLayout(frameLayout);
    frame->setStyleSheet("*{ border: 1px solid black; }");
    frame->setEnabled(false);

    layout->addWidget(frame);
    layout->addWidget(text);

    this->setLayout(layout);

    counter++;
    setSize();

    //connect(this, &chosenColor::mousePressEvent, )
}

void chosenColor::setSize()
{
    if(counter == 1)
    {
        this->setFixedSize(50,80);
        text->setText("Color 1");
    }
    else
    {
        this->setFixedSize(50,80);
        text->setText("Color 2");
        frame->setStyleSheet("*{ margin: 1px; }");
        frameLayout->setMargin(1);
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
