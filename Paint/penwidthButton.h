#ifndef PENWIDTH_H
#define PENWIDTH_H

#include <QMenu>
#include <QToolButton>

class penWidthButton : public QToolButton
{
    Q_OBJECT
public:
    penWidthButton(QWidget* parent = nullptr);
    void setParent(QObject*);
    void loadActions();
    void loadToolbar();

public slots:
    void sendActionIndex(QAction*);

signals:
    void sendBrushSize(int);

private:
    QMenu *menu;
    QList<QAction*> actionList;
};

#endif // PENWIDTH_H
