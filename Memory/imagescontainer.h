#ifndef IMAGESCONTAINER_H
#define IMAGESCONTAINER_H

#include <QIcon>

class ImagesContainer
{
public:
    ImagesContainer();
    QIcon getImg(int index);
    int getSize() { return images.size(); }
private:
    QVector<QIcon> images;

};

#endif // IMAGESCONTAINER_H
