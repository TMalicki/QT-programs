#ifndef BOARD_H
#define BOARD_H

#include <QGridLayout>
#include <QPushButton>
#include <QWidget>

class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = nullptr);

signals:

private:
    QVector<std::shared_ptr<QPushButton>> board;
    QPair<int, int> boardSize;
    std::unique_ptr<QGridLayout> gridLayout;

public slots:
    void initializeBoard(QPair<QString, QString>);
    void buttonClicked(int);
};

#endif // BOARD_H
