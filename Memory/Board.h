#ifndef BOARD_H
#define BOARD_H

#include <QGridLayout>
#include <QPushButton>
#include <QWidget>
#include <QTimer>
#include "imagescontainer.h"

class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = nullptr);

signals:

private:
    QVector<std::shared_ptr<QPushButton>> board;
    QVector<size_t> boardImgs;
    QVector<size_t> activeImgs;
    QVector<size_t> activeIndexes;

    QPair<int, int> boardSize;
    std::unique_ptr<QGridLayout> gridLayout;
    ImagesContainer imgContainer;
public slots:
    void initializeBoard(QPair<QString, QString>);
    void buttonClicked(int);
    void shuffleCards();
    void imgLoading();
    void makeBoard();
    bool pairCheck();
    void pairApproved();
    void pairDisapproved();
    void clearCards();
};

#endif // BOARD_H
