#include "screen.h"


Screen::Screen(QWidget *widget): QGraphicsView(widget)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene = new QGraphicsScene(this);

    screenSize = 850;
    pixSize = 20;

    setMinimumSize(screenSize, screenSize);

    colors.push_back(QColor("#72DDF7"));
    colors.push_back(QColor("#4AAD52"));
    colors.push_back(QColor("#FF312E"));

    base = QColor("#0B1005");
    axes = QColor("#c2bdab");

    select = QColor("#F75C03");

    iclr = 0;

    set();
}

int Screen::getDim()
{
   return calcN();
}

void Screen::setPixel(QPoint loc)
{
    int n = calcN();

    if(abs(loc.x()) > n || abs(loc.y()) > n) {
        return;
    }

    pixels[loc.x()+n][n-loc.y()]->setPixel();
}

void Screen::unsetPixel(QPoint loc)
{
    int n = calcN();

    if(abs(loc.x()) > n || abs(loc.y()) > n) {
        return;
    }

    pixels[loc.x()+n][n-loc.y()]->unsetPixel();
}

void Screen::useColor(QColor color)
{
    for(uint64_t i = 0; i < pixels.size(); i++) {
        for(uint64_t j = 0; j < pixels.size(); j++) {
            pixels[i][j]->changeColor(color);
        }
    }
}

void Screen::restoreColor()
{
    for(uint64_t i = 0; i < pixels.size(); i++) {
        for(uint64_t j = 0; j < pixels.size(); j++) {
            pixels[i][j]->changeColor(colors[iclr]);
        }
    }
}

void Screen::incSize()
{
    if(pixSize < 70) {
        pixSize += 2;
    }

    set();
}

void Screen::decSize()
{
    if(pixSize > 4) {
        pixSize -= 2;
    } else if (pixSize > 1) {
        pixSize -= 1;
    }

    set();
}

void Screen::changeColor()
{
    iclr = (iclr + 1)%colors.size();
    for(uint64_t i = 0; i < pixels.size(); i++) {
        for(uint64_t j = 0; j < pixels.size(); j++) {
            pixels[i][j]->changeColor(colors[iclr]);
        }
    }
}

void Screen::reset()
{
    for(uint64_t i = 0; i < pixels.size(); i++) {
        for(uint64_t j = 0; j < pixels.size(); j++) {
            pixels[i][j]->unsetPixel();
        }
    }
}

void Screen::getLoc(QPoint loc)
{
    emit sendLoc(loc);
}

int Screen::calcN()
{
    return (screenSize/pixSize - 1)/2
            + (screenSize%pixSize == 0? 0: 1);
}

void Screen::set()
{
    scene->setSceneRect(QRect(0, 0, screenSize, screenSize));
    this->setScene(scene);

    for(uint64_t i = 0; i < pixels.size(); i++) {
        for(uint64_t j = 0; j < pixels[i].size(); j++) {
            disconnect(pixels[i][j], &Pixel::sendLoc, this, &Screen::getLoc);
            delete pixels[i][j];
        }
    }

    pixels.clear();
    iclr = 0;

    int n = calcN();
    pixels.resize(2*n+1);
    QPoint tmp;
    for(int i = 0; i < 2*n+1; i++) {
        pixels[i].resize(2*n+1);
        for (int j = 0; j < 2*n+1; j++) {
            tmp.setX(i-n);
            tmp.setY(n-j);

            if( i == n || j == n) {
                pixels[i][j] = new Pixel(tmp, pixSize, colors[iclr], axes, select);
            } else {
                pixels[i][j] = new Pixel(tmp, pixSize, colors[iclr], base, select);
            }

            pixels[i][j]->setOffset(i*pixSize, j*pixSize);
            pixels[i][j]->setFlag(QGraphicsItem::ItemIsFocusable);
            pixels[i][j]->setFocus();
            connect(pixels[i][j], &Pixel::sendLoc, this, &Screen::getLoc);

            scene->addItem(pixels[i][j]);
        }
    }

    this->show();
}
