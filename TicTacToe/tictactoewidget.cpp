#include "tictactoewidget.h"

TicTacToeWidget::TicTacToeWidget(QWidget *parent) : QWidget(parent), score{0,0,0,0,0,0,0,0}
{
    gridLayout = new QGridLayout(this);
    size_t index{};
    actualPlayer = Player::Invalid;

    for(int row = 0; row < 3; row++)
    {
        for(int col = 0; col < 3; col++)
        {
            QPushButton* button = new QPushButton("");
            gridLayout->addWidget(button, row, col);
            mBoard.append(button);
            connect(button, &QPushButton::clicked, [=]{ buttonClicked(index); });
            index++;
        }
    }
}

void TicTacToeWidget::buttonClicked(int index)
{
    auto button = mBoard[index];
    if(actualPlayer == Player::Invalid || button->text() != "") return;
    else
    {
        if(actualPlayer == Player::Player1)
        {
            button->setText("X");
        }
        else if(actualPlayer == Player::Player2)
        {
            button->setText("O");
        }
    }
    addPoints(index);
    checkWinCondition();

    if(actualPlayer == Player::Player1)
    {
        actualPlayer = Player::Player2;
    }
    else if(actualPlayer == Player::Player2)
    {
        actualPlayer = Player::Player1;
    }
}

void TicTacToeWidget::initNewGame()
{
    for(auto temp : mBoard)
    {
        temp->setText("");
    }
    actualPlayer = Player::Player1;

    for(size_t i = 0; i < 9; i++)
    {
        score[i] = 0;
    }
}

void TicTacToeWidget::checkWinCondition()
{
    Player winner = Player::Invalid;

    if(checkIfDraw()) winner = Player::Draw;
    else
    {
        if(actualPlayer != Player::Invalid)
        {
            for(size_t i = 0; i < 9; i++)
            {
                if(score[i] == 3) winner = Player::Player1;
                else if(score[i] == -3) winner = Player::Player2;
            }
        }
    }

    if(winner != Player::Invalid)
    {
        gameOver(winner);
    }
}

void TicTacToeWidget::gameOver(TicTacToeWidget::Player winner)
{
    qDebug() << winner;
}

void TicTacToeWidget::addPoints(int index)
{
    auto coords = convertToArray(index);

    int point{};
    if(actualPlayer == Player::Player1) point = 1;
    else if(actualPlayer == Player::Player2) point = -1;

    score[coords.first] += point;
    score[3 + coords.second] += point;
    if(coords.first == coords.second) score[2 * 3] += point;
    if(3 - 1 - coords.second == coords.first) score[2 * 3 + 1] += point;
}

QPair<int, int> TicTacToeWidget::convertToArray(int index)
{
    QPair<int, int> coords {0,0};
    coords.first = index/3;
    coords.second = index - coords.first * 3;

    return coords;
}

bool TicTacToeWidget::checkIfDraw()
{
    int counter{};
    for(int i = 0; i < mBoard.size(); i++)
    {
        if(mBoard[i]->text() == "") counter++;
    }

    if(counter == 0) return true;
    else return false;
}
