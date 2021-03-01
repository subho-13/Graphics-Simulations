#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <cstdint>

using namespace std;

#include <QGraphicsView>
#include <QObject>
#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "pixel.h"

class Screen : public QGraphicsView
{
    Q_OBJECT
public:
    Screen(QWidget* widget = nullptr);
    bool isPixelSet(QPoint loc);
    bool isPixelColored(QPoint loc);
    void getDimensions(int& xmin, int& ymin, int& xmax, int& ymax);
    void colorPixel(QPoint loc);
public slots:
   void setPixel(QPoint loc);

   void incPixSize();
   void decPixSize();

   void changeSetPixelColor();
   void resetScreen();
signals:
    void sendLoc(QPoint loc);
private slots:
    void getLoc(QPoint loc);
private:
    QRgb allColors[6];
    int currColorIndex;

    QGraphicsScene *scene;
    int pixelSize;
    int screenSize;

    QImage setPixelImage;
    QImage unsetPixelImage;
    QImage unsetPixelImageAxes;
    QImage selectPixelImage;

    vector<vector<Pixel *>> pixels;
    void setScreen();
    QImage makeImage(const QRgb& color);
};

#endif // SCREEN_H
