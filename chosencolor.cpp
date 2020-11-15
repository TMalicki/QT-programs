#include "chosencolor.h"

chosenColor::chosenColor(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout;

    colorBox = new QLineEdit("");
    colorBox->setEnabled(false);
    colorBox->setStyleSheet("background-color: red");
    colorBox->setFixedSize(40,40);

    text = new QLabel("Color 1");
    text->setAlignment(Qt::AlignCenter);
    text->setFixedSize(colorBox->size());

    layout->addWidget(colorBox);
    layout->addWidget(text);

    this->setLayout(layout);
    this->setFixedSize(60,80);
}
