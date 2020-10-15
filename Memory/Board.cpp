#include "Board.h"
#include <QDebug>

Board::Board(QWidget *parent) : QWidget(parent)
{
    gridLayout = std::make_unique<QGridLayout>(this);
    this->setEnabled(false);
}

void Board::initializeBoard(QPair<QString, QString> size)
{
    boardSize = {size.first.toInt(), size.second.toInt()};
    this->setEnabled(true);
    int index {0};

    for(int i = 0; i < boardSize.second; i++)
    {
        for(int j = 0; j < boardSize.first; j++)
        {
            std::shared_ptr<QPushButton> button = std::make_shared<QPushButton>("");
            button->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

            board.append(button);
            gridLayout->addWidget(button.get(), i, j);
            qDebug() << index;
            connect(button.get(), &QPushButton::clicked, [this, index](){ buttonClicked(index); });
            index++;
        }
    }
}

void Board::buttonClicked(int index)
{
    auto button = board[index];
    button->setIcon(QIcon(":/images/thor.jpg"));
    button->setIconSize(button->size() / 1.2);
}
