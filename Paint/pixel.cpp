#include "pixel.h"

Pixel::Pixel(QPoint loc) {
    this->loc = loc;
    pressedTimes = 0;
    pixelIsSet = false;
    pixelIsSelected = false;
    pixelIsColored = false;}

void Pixel::setPixel() {
    setPixmap(setPixelImage);
    pressedTimes = 0;
    pixelIsSet = true;
    pixelIsSelected = false;
    pixelIsColored = false;
}

void Pixel::unsetPixel() {
    setPixmap(unsetPixelImage);
    pixelIsSet = false;
    pixelIsSelected = false;
    pixelIsColored = false;
}

void Pixel::colorPixel(const QImage color)
{
    setPixmap(QPixmap::fromImage(color));
    pixelIsColored = true;
}

void Pixel::setImage(const QImage &set, const QImage unset, const QImage &select)
{
    setPixelImage = QPixmap::fromImage(set);
    unsetPixelImage = QPixmap::fromImage(unset);
    selectPixelImage = QPixmap::fromImage(select);
}

void Pixel::changeSetPixelImage(const QImage set) {
    setPixelImage = QPixmap::fromImage(set);
}

bool Pixel::isPixelSet()
{
    return pixelIsSet;
}

bool Pixel::isPixelColored()
{
    return pixelIsColored;
}
void Pixel::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    pressedTimes++;
    if (pressedTimes%2 == 1) {
        setPixmap(selectPixelImage);
        pixelIsSet = false;
        pixelIsSelected = true;
        pixelIsColored = false;
        emit sendLoc(loc);
    } else {
        unsetPixel();
    }
}


