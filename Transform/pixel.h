#ifndef PIXEL_H
#define PIXEL_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QPoint>

class Pixel : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Pixel(QPoint loc, int size, QColor set, QColor unset, QColor select);
    void setPixel();
    void setPixel(QColor color);
    void changeColor(QColor color);
    void unsetPixel();
public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
signals:
    void sendLoc(QPoint loc);
private:
    QPoint loc;

    QColor set;
    QColor unset;
    QColor select;

    QPixmap setIm;
    QPixmap unsetIm;
    QPixmap selectIm;

    int size;

    QImage createImage(QColor color);
};

#endif // PIXEL_H
