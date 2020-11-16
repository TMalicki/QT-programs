#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "pensil.h"
#include "penwidthButton.h"
#include "chosencolor.h"

#include <QMainWindow>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    Ui::MainWindow *ui;
    penWidth* widthPen;
};
#endif // MAINWINDOW_H
