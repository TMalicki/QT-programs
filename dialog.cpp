#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->EditName1, &QLineEdit::textChanged, this, &Dialog::updateOkButtonState);
    connect(ui->EditName2, &QLineEdit::textChanged, this, &Dialog::updateOkButtonState);
    updateOkButtonState();
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

void Dialog::updateOkButtonState()
{
    QPushButton* okButton = ui->Ok;
    okButton->setEnabled(!ui->EditName1->text().isEmpty() && !ui->EditName2->text().isEmpty());
}
