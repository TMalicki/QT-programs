#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenuBar>
#include <QGraphicsView>


#include <QDebug>
#include <QToolButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), widthPen{}
{
    ui->setupUi(this);
    ui->barView->setVisible(false);

    widthPen = new penWidthButton(this);

    ui->barTools->addWidget(widthPen);
    ui->barTools->addWidget(ui->firstColorBox);
    ui->barTools->addWidget(ui->secondColorBox);

    DrawArea* drawArea = new DrawArea(ui->drawableArea);
    loadDrawArea(drawArea);

    connect(ui->actionTools, &QAction::triggered,
            [=](){ ui->barTools->setVisible(true); ui->barView->setVisible(false); });
    connect(ui->actionView, &QAction::triggered,
            [=](){ ui->barView->setVisible(true); ui->barTools->setVisible(false); });
    connect(widthPen, &penWidthButton::sendBrushSize, [=](int size){ drawArea->setBrushSize(size); });
    connect(ui->firstColorBox, &chosenColor::click,
            [=]()
            { drawArea->setColor(ui->firstColorBox->getColor());
              ui->firstColorBox->setHighlightBackground();
              ui->secondColorBox->resetHighlightBackground(); });
    connect(ui->secondColorBox, &chosenColor::click,
            [=]()
            { drawArea->setColor(ui->secondColorBox->getColor());
              ui->secondColorBox->setHighlightBackground();
              ui->firstColorBox->resetHighlightBackground(); });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadDrawArea(DrawArea* drawArea)
{
    this->setCentralWidget(ui->drawableArea);
    ui->drawableArea->setScene(drawArea);
    ui->drawableArea->setSceneRect(-300,-300,300,300);
    ui->drawableArea->resize(600,600);
}




