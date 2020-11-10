#include "penwidth.h"
#include <QDebug>

penWidth::penWidth(QWidget* parent) : QToolButton(parent)
{
    loadActions();
    loadToolbar();
    connect(menu, SIGNAL(triggered(QAction*)), this, SLOT(sendActionIndex(QAction*)));

}

void penWidth::setParent(QObject* parent)
{
    for(auto& action : actionList)
    {
        action->setParent(parent);
    }
}

void penWidth::loadActions()
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

void penWidth::loadToolbar()
{
    setMenu(menu);
    setIcon(QIcon(":/Icons/Icons/lineWidth.png"));
    setPopupMode(QToolButton::InstantPopup);
}

void penWidth::sendActionIndex(QAction* action)
{
    emit sendBrushSize(action->data().toInt());
}


