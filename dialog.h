#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void setPlayer1Name(const QString &name);
    void setPlayer2Name(const QString &name);
    QString getPlayer1Name() const;
    QString getPlayer2Name() const;
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
