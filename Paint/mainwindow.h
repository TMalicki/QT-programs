#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "pensilSettings.h"
#include "penwidthButton.h"
#include "chosencolor.h"
#include "drawarea.h"

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

    void loadDrawArea(DrawArea*);
protected:
    Ui::MainWindow *ui;

    penWidthButton* widthPen;
};
#endif // MAINWINDOW_H
