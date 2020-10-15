#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gridParameters = new Dialog;

    connect(ui->actionGridSettings, &QAction::triggered, [&]() { gridParameters->exec(); });
    connect(ui->actionQuit, &QAction::triggered, qApp, &QApplication::quit);
    connect(this->gridParameters->getBtn(), &QPushButton::clicked,
            [&]{ ui->board->initializeBoard(gridParameters->loadData()); });  // maybe here should be observer pattern (between Board and Dialog class)
}

MainWindow::~MainWindow()
{
    delete ui;
}


