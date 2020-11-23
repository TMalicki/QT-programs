#include "chosencolor.h"
#include <QDebug>
#include <QPainter>
#include <QStyleOption>

int chosenColor::counter{0};

chosenColor::chosenColor(QWidget *parent) : QWidget(parent), color{}
{
    layout = new QVBoxLayout(this);

    colorBox = new QLabel("");
    //colorBox->setAlignment(Qt::AlignCenter);
    colorBox->size();
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
    this->setFixedSize(44,70);

    if(counter == 1)
    {
        text->setText("Color 1");
        color = Qt::black;
        layout->setContentsMargins(6,2,6,2);
        layout->setSpacing(2);
    }
    else
    {
        text->setText("Color 2");
        color = Qt::red;
        layout->setContentsMargins(8,4,8,4);
    }
}

void chosenColor::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);

    QPalette pal = colorBox->palette();
    pal.setColor(colorBox->backgroundRole(), color);
    colorBox->setPalette(pal);
    colorBox->setAutoFillBackground(true);

    this->setAutoFillBackground(true);

    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}

void chosenColor::mousePressEvent(QMouseEvent *event)
{
    emit click();
}
