#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPoint>
#include <QThread>
#include <chrono>
#include <QTime>
#include <QCoreApplication>

#include "screen.h"
#include "pointqueue.h"
#include "line.h"
#include "ellipse.h"
#include "circle.h"
#include "unistd.h"
#include "fill.h"
#include "polygon.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void showLoc(QPoint loc);
    void paint();
public:
    void showExecTime(uint64_t milliseconds);
    void delay()
    {
        QTime dieTime= QTime::currentTime().addMSecs(10);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
private:
    Ui::MainWindow *ui;
    PointQueue queue;
};
#endif // MAINWINDOW_H
