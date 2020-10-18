#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->loadBtn->setEnabled(false);

    connect(ui->columnInput, &QLineEdit::textChanged, this, &Dialog::updateLoadDataBtn);
    connect(ui->rowInput, &QLineEdit::textChanged, this, &Dialog::updateLoadDataBtn);
    //connect(ui->loadBtn, &QPushButton::clicked, this, &Dialog::loadData);
    connect(ui->loadBtn, &QPushButton::clicked, this, &Dialog::getBtnActive);
    connect(ui->loadBtn, &QPushButton::clicked, this, &Dialog::accept);
}

Dialog::~Dialog()
{
    delete ui;
}

QPair<QString, QString> Dialog::loadData()
{
    return QPair<QString, QString>(ui->columnInput->text(), ui->rowInput->text());
}

void Dialog::updateLoadDataBtn()
{
    if(!ui->columnInput->text().isEmpty() && !ui->rowInput->text().isEmpty()
       && ui->columnInput->text().toInt() * ui->rowInput->text().toInt() % 2 == 0) ui->loadBtn->setEnabled(true);
}

QPushButton* Dialog::getBtn()
{
    return ui->loadBtn;
}

bool Dialog::getBtnActive()
{
    return true;
}
