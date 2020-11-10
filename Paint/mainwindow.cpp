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
    widthPen->setParent(this);
    ui->barTools->addWidget(widthPen);

    /*
    ui->barTools->addWidget(ui->brush);
    ui->barTools->addWidget(ui->lineWidth);

    ui->brush->addAction(new QAction("Brush 1", this));
    ui->brush->addAction(new QAction("Brush 2", this));

*/

    setCentralWidget(ui->drawableArea);

    connect(ui->actionTools, &QAction::triggered,
            [=](){ ui->barTools->setVisible(true); ui->barView->setVisible(false); });

    connect(ui->actionView, &QAction::triggered,
            [=](){ ui->barView->setVisible(true); ui->barTools->setVisible(false); });

    //connect(widthPen, &penWidth::sendBrushSize, ui->drawableArea, &DrawArea::setBrushSize);

    DrawArea* drawArea = new DrawArea(ui->drawableArea);
    ui->drawableArea->setScene(drawArea);
    ui->drawableArea->setSceneRect(-300,-300,300,300);
    ui->drawableArea->resize(600,600);


    connect(widthPen, &penWidth::sendBrushSize, [=](int test){ drawArea->setBrushSize(test); qDebug() << test; });
}

MainWindow::~MainWindow()
{
    delete ui;
}





