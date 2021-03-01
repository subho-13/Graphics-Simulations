#ifndef PIXEL_H
#define PIXEL_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <QPoint>

class Pixel : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT;
public:
    Pixel(QPoint loc);
    void setPixel();
    void unsetPixel();
    void colorPixel(const QImage color);
    void setImage(const QImage& set, const QImage unset, const QImage& select);
    void changeSetPixelImage(const QImage set);
    bool isPixelSet();
    bool isPixelColored();
public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
signals:
    void sendLoc(QPoint loc);
private:
    QPoint loc;

    QPixmap setPixelImage;
    QPixmap unsetPixelImage;
    QPixmap selectPixelImage;

    int pressedTimes;
    bool pixelIsSet;
    bool pixelIsSelected;
    bool pixelIsColored;
};

#endif // PIXEL_H
