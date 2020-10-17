#include "Board.h"
#include <QDebug>
#include <algorithm>
#include <random>

Board::Board(QWidget *parent) : QWidget(parent)
{
    gridLayout = std::make_unique<QGridLayout>(this);
    this->setEnabled(false);
}

void Board::initializeBoard(QPair<QString, QString> size)
{
    boardSize = {size.first.toInt(), size.second.toInt()};
    boardImgs.resize(boardSize.first * boardSize.second);

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
            connect(button.get(), &QPushButton::clicked, [this, index](){ buttonClicked(index); });
            index++;
        }
    }

    imgLoading();
    shuffleCards();
}

void Board::buttonClicked(int index)
{
    auto button = board[index];

    button->setIcon(imgContainer.getImg(boardImgs[index]));

    button->setIconSize(button->size() / 1.2);
}

void Board::shuffleCards()
{
    auto rng = std::default_random_engine{};
    std::shuffle(std::begin(boardImgs), std::end(boardImgs), rng);

    for(auto card : boardImgs)
    {
        qDebug() << card;
    }
}

void Board::imgLoading()
{
    auto imgIncrement = 0;

    auto boardSize = board.size();
    auto boardIncrement = 0;

    while(boardIncrement < boardSize)
    {
        boardImgs[boardIncrement] = imgIncrement;
        boardImgs[boardIncrement+1] = imgIncrement;
        boardIncrement += 2;
        imgIncrement++;
    }
}
