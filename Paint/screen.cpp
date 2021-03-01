#include "screen.h"

Screen::Screen(QWidget *widget) : QGraphicsView(widget)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene = new QGraphicsScene(this);
    pixelSize = 20;
    screenSize = 600;

    setMinimumSize(screenSize+5, screenSize+5);

    allColors[0] = qRgb(20, 235, 150);
    allColors[1] = qRgb(255, 0, 127);
    allColors[2] = qRgb(245, 255, 153);
    allColors[4] = qRgb(245, 20, 20);
    allColors[3] = qRgb(150, 0, 245);
    allColors[5] = qRgb(255, 170, 60);

    setScreen();
}

bool Screen::isPixelSet(QPoint loc)
{
    int n = (screenSize/pixelSize - 1)/2 + 1;

    if((loc.x() > n || loc.x() < -1*n) || (loc.y() > n || loc.y() < -1*n)) {
        return true;
    }

    return pixels[loc.x()+n][n-loc.y()]->isPixelSet();
}

bool Screen::isPixelColored(QPoint loc)
{
    int n = (screenSize/pixelSize - 1)/2 + 1;

    if((loc.x() > n || loc.x() < -1*n) || (loc.y() > n || loc.y() < -1*n)) {
        return true;
    }

    return pixels[loc.x()+n][n-loc.y()]->isPixelColored();
}

void Screen::getDimensions(int &xmin, int &ymin, int &xmax, int &ymax)
{
    int n = (screenSize/pixelSize - 1)/2 + 1;
    xmin = -1*n;
    ymin = -1*n;
    xmax = 1*n;
    ymax = 1*n;
}

void Screen::colorPixel(QPoint loc)
{
    int n = (screenSize/pixelSize - 1)/2 + 1;

    if((loc.x() > n || loc.x() < -1*n) || (loc.y() > n || loc.y() < -1*n)) {
        return;
    }

    pixels[loc.x()+n][n-loc.y()]->colorPixel(
                makeImage(allColors[(currColorIndex+1)%6])
            );
}

void Screen::incPixSize()
{
    if (pixelSize < 10) {
        pixelSize += 1;
    } else if (pixelSize < 70) {
         pixelSize += 5;
    }
    setScreen();
}

void Screen::decPixSize()
{
    if (pixelSize > 5) {
        pixelSize -= 5;
    } else {
        if(pixelSize > 2) {
            pixelSize -= 1;
        }
    }

    setScreen();
}

void Screen::changeSetPixelColor()
{
    currColorIndex = (currColorIndex + 1)%6;
    setPixelImage = makeImage(allColors[currColorIndex]);

    for(uint64_t i = 0; i < pixels.size(); i++) {
        for(uint64_t j = 0; j < pixels[i].size(); j++) {
            pixels[i][j]->changeSetPixelImage(setPixelImage);
        }
    }
}

void Screen::setScreen() {
    scene->setSceneRect(QRect(0, 0, screenSize, screenSize));
    this->setScene(scene);


    for(uint64_t i = 0; i < pixels.size(); i++) {
        for(uint64_t j = 0; j < pixels[i].size(); j++) {
            disconnect(pixels[i][j], &Pixel::sendLoc, this, &Screen::getLoc);
            delete pixels[i][j];
        }
    }

    pixels.clear();

    currColorIndex = 0;

    setPixelImage = makeImage(allColors[currColorIndex]);
    unsetPixelImage = makeImage(qRgb(43, 43, 43));
    unsetPixelImageAxes = makeImage(qRgb(180, 180, 180));
    selectPixelImage = makeImage(qRgb(255, 200, 50));

    int n = (screenSize/pixelSize - 1)/2 + 1;
    pixels.resize(2*n+1);
    QPoint tmp;
    for (int i = 0; i < 2*n+1; i++) {
        pixels[i].resize(2*n+1);
        for (int j = 0; j < 2*n+1; j++) {
            tmp.setX(i-n);
            tmp.setY(n-j);

            pixels[i][j] = new Pixel(tmp);

            if(i == n || j == n) {
                pixels[i][j]->setImage(setPixelImage, unsetPixelImageAxes, selectPixelImage);
            } else {
                pixels[i][j]->setImage(setPixelImage, unsetPixelImage, selectPixelImage);
            }

            pixels[i][j]->unsetPixel();
            pixels[i][j]->setOffset(i*pixelSize, j*pixelSize);
            pixels[i][j]->setFlag(QGraphicsItem::ItemIsFocusable);
            pixels[i][j]->setFocus();
            connect(pixels[i][j], &Pixel::sendLoc, this, &Screen::getLoc);

            scene->addItem(pixels[i][j]);
        }
    }

    this->show();
}

QImage Screen::makeImage(const QRgb& color)
{
    QImage image(pixelSize, pixelSize, QImage::Format_ARGB32);
    image.fill(qRgb(100, 100, 100));
    for (int i = 0; i < pixelSize-1; i++) {
        for (int j = 0; j < pixelSize-1; j++) {
            image.setPixel(i, j, color);
        }
    }
    return image;
}

void Screen::resetScreen()
{
    for(uint64_t i = 0; i < pixels.size(); i++) {
        for(uint64_t j = 0; j < pixels[i].size(); j++) {
            pixels[i][j]->unsetPixel();
        }
    }
}

void Screen::setPixel(QPoint loc) {
    int n = (screenSize/pixelSize - 1)/2 + 1;

    if((loc.x() > n || loc.x() < -1*n) || (loc.y() > n || loc.y() < -1*n)) {
        return;
    }

    pixels[loc.x()+n][n-loc.y()]->setPixel();
}

void Screen::getLoc(QPoint loc)
{
    emit sendLoc(loc);
}
