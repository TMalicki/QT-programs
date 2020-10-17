#include "imagescontainer.h"

ImagesContainer::ImagesContainer()
{
    images.append(QIcon(":/images/thor.jpg"));
    images.append(QIcon(":/images/hulk.jpg"));
    images.append(QIcon(":/images/spiderMan.jpeg"));
    images.append(QIcon(":/images/ironMan.jpg"));
    images.append(QIcon(":/images/blackPanther.jpg"));
    images.append(QIcon(":/images/blackWidow.jpg"));
    images.append(QIcon(":/images/captainAmerica.jpg"));
    images.append(QIcon(":/images/captainMarvel.jpg"));
}

QIcon ImagesContainer::getImg(int index)
{
    return images.at(index);
}

