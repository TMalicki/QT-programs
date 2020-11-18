#include "penwidthButton.h"
#include <QDebug>
#include <QApplication>

penWidthButton::penWidthButton(QWidget* parent) : QToolButton(parent)
{
    loadActions();
    loadToolbar();
    setParent(this);

    connect(menu, SIGNAL(triggered(QAction*)), this, SLOT(sendActionIndex(QAction*)));
}

void penWidthButton::setParent(QObject* parent)
{
    for(auto& action : actionList)
    {
        action->setParent(parent);
    }
}

void penWidthButton::loadActions()
{
    menu = new QMenu();
    actionList.append(new QAction(QIcon(":/Icons/Icons/widthOne.png"),"1 PX"));
    actionList.append(new QAction(QIcon(":/Icons/Icons/widthThree.png"),"3 PX"));
    actionList.append(new QAction(QIcon(":/Icons/Icons/widthSix.png"),"6 PX"));
    actionList.append(new QAction(QIcon(":/Icons/Icons/widthEight.png"),"8 PX"));

    for(auto& action : actionList)
    {
        action->setData(action->text()[0].digitValue());
        menu->addAction(action);
    }
}

void penWidthButton::loadToolbar()
{
    setMenu(menu);
    setIcon(QIcon(":/Icons/Icons/lineWidth.png"));
    setPopupMode(QToolButton::InstantPopup);
}

void penWidthButton::sendActionIndex(QAction* action)
{
    emit sendBrushSize(action->data().toInt());
}

