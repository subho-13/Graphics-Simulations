#ifndef SCREEN_H
#define SCREEN_H

#include <QGraphicsView>
#include <QObject>
#include <QGraphicsScene>

#include <vector>
#include <cstdlib>
using namespace std;

#include "pixel.h"

class Screen : public QGraphicsView
{
    Q_OBJECT
public:
    Screen(QWidget* widget = nullptr);
    int getDim();
    void setPixel(QPoint loc);
    void unsetPixel(QPoint loc);
    void useColor(QColor color);
    void restoreColor();
public slots:
    void incSize();
    void decSize();
    void changeColor();
    void reset();
signals:
    void sendLoc(QPoint loc);
private slots:
    void getLoc(QPoint loc);
private:
    vector<QColor> colors;
    int iclr;
    QColor axes;
    QColor base;
    QColor select;

    int screenSize;
    int pixSize;

    vector<vector<Pixel*>> pixels;
    QGraphicsScene* scene;

    int calcN();
    void set();
};

#endif // SCREEN_H
