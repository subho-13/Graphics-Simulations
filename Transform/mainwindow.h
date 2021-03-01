#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QMessageBox>
#include <QTime>

#include "line.h"
#include "polygon.h"
#include "pointq.h"
#include "transform.h"
#include "window.h"
#include "clip.h"

#define PI 3.14159
#define DX 1.0
#define DSCALE 1.2
#define DTHETA 2*PI/180
#define DELAY 5

#define LINECLR "#FF8200"
#define PIVOTCLR "#F2F2F2"
#define WINDOWCLR "#F8F81E"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setPixels(const vector<QPoint>& points);
    void setPixels(const vector<QPoint>& points, QColor color);
    void unsetPixels(const vector<QPoint>& points);
    ~MainWindow();
public slots:
    void reset();
    void line();
    void polygon();
    void pivot();
    void window();

    void switchDelay();
    void addPoint(QPoint loc);

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    void rotateAnti();
    void rotateClock();

    void scaleUp();
    void scaleDown();

    void reflect();
    void shear();

    void repaint();
    void clip();

    void incGridSize();
    void decGridSize();
private:
    Ui::MainWindow *ui;

    vector<Line> lines;
    vector<Polygon> polygons;
    vector<Window> windows;

    vector<QPoint> pivots;

    bool toDelay;
    PointQ pointQ;
    Transform transform;

    void delay(int ms);
    vector<QPointF> convQPointVec(const vector<QPoint>& points);
    float convDegreeRadian(float angle);

    Polygon rotatePivotAnti(const Polygon& p, QPoint pivot);
    Polygon rotatePivotClock(const Polygon& p, QPoint pivot);
    Polygon scalePivotUp(const Polygon& p, QPoint pivot);
    Polygon scalePivotDown(const Polygon& p, QPoint pivot);
    Polygon reflectPivot(const Polygon& p, QPoint pivot);
    Polygon reflectLine(const Polygon& p, const Line& line);
    Polygon shearLine(const Polygon& p, const Line& line);
};
#endif // MAINWINDOW_H
