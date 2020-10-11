#ifndef TICTACTOEWIDGET_H
#define TICTACTOEWIDGET_H

#include <QGridLayout>
#include <QPushButton>
#include <QWidget>
#include <QDebug>
#include <QPair>

class TicTacToeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TicTacToeWidget(QWidget *parent = nullptr);

    enum class Player { Invalid, Player1, Player2, Draw };
    Q_ENUM(Player);

    void buttonClicked(int);
    void initNewGame();
    void checkWinCondition();
    void gameOver(Player);
    void addPoints(int);
    QPair<int, int> convertToArray(int);
    bool checkIfDraw();
private:
    QVector<QPushButton*> mBoard;
    QGridLayout* gridLayout;
    Player actualPlayer;
    int score[8];   // [row1, row2, row3, col1, col2, col3, diag1, diag2]
signals:

};

#endif // TICTACTOEWIDGET_H
