#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenuBar>
#include <QGraphicsView>
#include "drawarea.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->barView->setVisible(false);

    setCentralWidget(ui->drawableArea);

    connect(ui->actionTools, &QAction::triggered,
            [=](){ ui->barTools->setVisible(true); ui->barView->setVisible(false); });

    connect(ui->actionView, &QAction::triggered,
            [=](){ ui->barView->setVisible(true); ui->barTools->setVisible(false); });

    DrawArea* drawArea = new DrawArea(ui->drawableArea);
    ui->drawableArea->setScene(drawArea);

    ui->drawableArea->setSceneRect(-300,-300,300,300);
    ui->drawableArea->resize(600,600);
}

MainWindow::~MainWindow()
{
    delete ui;
}



