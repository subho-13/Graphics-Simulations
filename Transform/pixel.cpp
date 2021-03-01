#include "pixel.h"

Pixel::Pixel(QPoint loc, int size, QColor set,
             QColor unset, QColor select)
{
    this->loc = loc;
    this->size = size;
    this->set = set;
    this->unset = unset;
    this->select = select;

    setIm = QPixmap::fromImage(createImage(set));
    unsetIm = QPixmap::fromImage(createImage(unset));
    selectIm = QPixmap::fromImage(createImage(select));

    unsetPixel();
}

void Pixel::setPixel()
{
    setPixmap(setIm);
}

void Pixel::setPixel(QColor color)
{
    set = color;
    setIm = QPixmap::fromImage(createImage(set));
    setPixel();
}

void Pixel::changeColor(QColor color)
{
    set = color;
    setIm = QPixmap::fromImage(createImage(set));
}

void Pixel::unsetPixel()
{
    setPixmap(unsetIm);
}

void Pixel::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setPixmap(selectIm);
    emit sendLoc(loc);
}

QImage Pixel::createImage(QColor color)
{
    QImage image(size, size, QImage::Format_RGB32);
    image.fill(QColor("#7F7F7F"));

    int psize = size-1;

    if(size < 7) {
        psize = size;
    }

    for (int i = 0; i < psize; i++) {
        for (int j = 0; j < psize; j++) {
            image.setPixelColor(i, j, color);
        }
    }

    return image;
}
