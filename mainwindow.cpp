#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenuBar>
#include <QGraphicsView>

#include "drawarea.h"
#include <QDebug>
#include <QToolButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), widthPen{}
{
    ui->setupUi(this);
    ui->barView->setVisible(false);

    widthPen = new penWidth(this);
    ui->barTools->addWidget(widthPen);

    chosenColor1 = new chosenColor(this);
    ui->barTools->addWidget(chosenColor1);
    chosenColor2 = new chosenColor(this);
    ui->barTools->addWidget(chosenColor2);

    setCentralWidget(ui->drawableArea);

    DrawArea* drawArea = new DrawArea(ui->drawableArea);
    ui->drawableArea->setScene(drawArea);
    ui->drawableArea->setSceneRect(-300,-300,300,300);
    ui->drawableArea->resize(600,600);

    connect(ui->actionTools, &QAction::triggered,
            [=](){ ui->barTools->setVisible(true); ui->barView->setVisible(false); });

    connect(ui->actionView, &QAction::triggered,
            [=](){ ui->barView->setVisible(true); ui->barTools->setVisible(false); });
    connect(widthPen, &penWidth::sendBrushSize, [=](int size){ drawArea->setBrushSize(size); });
}

MainWindow::~MainWindow()
{
    delete ui;
}




