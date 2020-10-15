#include "imagescontainer.h"

ImagesContainer::ImagesContainer()
{
    images.append(QIcon(":/images/thor.jpg"));
}

QIcon ImagesContainer::getImg(int index)
{
    return images.at(index);
}

