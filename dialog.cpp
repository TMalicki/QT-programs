#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setPlayer1Name(const QString &name)
{
    ui->EditName1->setText(name);
}

void Dialog::setPlayer2Name(const QString &name)
{
    ui->EditName2->setText(name);
}

QString Dialog::getPlayer1Name() const
{
    return ui->EditName1->text();
}

QString Dialog::getPlayer2Name() const
{
    return ui->EditName2->text();
}
