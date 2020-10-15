#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "Board.h"
#include <QPair>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void updateLoadDataBtn();
    QPushButton* getBtn();
    QPair<QString, QString> loadData();

private:
    Ui::Dialog *ui;
   // Board * board;

public slots:
    bool getBtnActive();
};

#endif // DIALOG_H
