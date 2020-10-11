#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->startGame, &QPushButton::clicked, this, &MainWindow::startNewGame);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startNewGame()
{
    ui->player1Name->setText("Tom");
    ui->player2Name->setText("Anna");
    ui->gameBoard->initNewGame();
}


