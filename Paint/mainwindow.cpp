#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenuBar>
#include <QGraphicsView>

#include "drawarea.h"


#include <QToolButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->barView->setVisible(false);
    //ui->barTools->addWidget(mPenSize.setObject());

  /*
    QMenu *menu = new QMenu();
    QAction *testAction = new QAction("test menu item", this);
    menu->addAction(testAction);

    QToolButton* toolButton = new QToolButton();
    toolButton->setMenu(menu);
    toolButton->setIcon(QIcon(":/Icons/Icons/lineWidth.png"));
    toolButton->setPopupMode(QToolButton::InstantPopup);
    toolButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
    ui->barTools->addWidget(toolButton);
*/
    ui->barTools->addWidget(ui->brush);
    ui->barTools->addWidget(ui->lineWidth);

    ui->brush->addAction(new QAction("Brush 1", this));
    ui->brush->addAction(new QAction("Brush 2", this));

    ui->lineWidth->addAction(new QAction("5 PX", this));
    ui->lineWidth->addAction(new QAction("8 PX", this));


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





