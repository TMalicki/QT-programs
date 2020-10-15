#ifndef IMAGESCONTAINER_H
#define IMAGESCONTAINER_H

#include <QIcon>

class ImagesContainer
{
public:
    ImagesContainer();
    QIcon getImg(int index);
private:
    QVector<QIcon> images;

};

#endif // IMAGESCONTAINER_H
