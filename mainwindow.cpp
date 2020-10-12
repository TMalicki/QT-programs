#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->startGame, &QPushButton::clicked, this, &MainWindow::startNewGame);
    connect(ui->gameBoard, &TicTacToeWidget::playerChanged, this, &MainWindow::updateNameLabels);
    connect(ui->gameBoard, &TicTacToeWidget::gameOver, this, &MainWindow::handleGameOver);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLabelBold(QLabel *label, bool isBold)
{
    QFont f = label->font();
    f.setBold(isBold);
    label->setFont(f);
}

void MainWindow::startNewGame()
{
    Dialog dialog(this);
    if(dialog.exec() == QDialog::Rejected) return;

    ui->player1Name->setText(dialog.getPlayer1Name());
    ui->player2Name->setText(dialog.getPlayer2Name());
    ui->gameBoard->initNewGame();
}

void MainWindow::updateNameLabels()
{
    setLabelBold(ui->player1Name, ui->gameBoard->getCurrentPlayer() == TicTacToeWidget::Player::Player1);
    setLabelBold(ui->player2Name, ui->gameBoard->getCurrentPlayer() == TicTacToeWidget::Player::Player2);
}

void MainWindow::handleGameOver(TicTacToeWidget::Player winner)
{
    QString message;
    if(winner == TicTacToeWidget::Player::Draw)
    {
        message = "Game ended with a draw";
    }
    else
    {
        if(winner == TicTacToeWidget::Player::Player1)
        {
            message = "Player 1 wins a game";
        }
        else
        {
            message = "Player 2 wins a game";
        }
    }
    QMessageBox::information(this, "Info", message);
}


