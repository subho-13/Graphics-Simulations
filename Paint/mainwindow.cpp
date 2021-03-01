#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setFixedSize(912, 776);
    ui->setupUi(this);

    ui->location->setAlignment(Qt::AlignCenter);
    ui->time->setAlignment(Qt::AlignCenter);

    connect(ui->screen,&Screen::sendLoc, this, &MainWindow::showLoc);
    connect(ui->screen, &Screen::sendLoc, &queue, &PointQueue::add);


    connect(ui->draw,&QPushButton::pressed, this, &MainWindow::paint);
    connect(ui->reset,&QPushButton::pressed,ui->screen, &Screen::resetScreen);
    connect(ui->chngPixClr,&QPushButton::pressed, ui->screen, &Screen::changeSetPixelColor);
    connect(ui->incPixSz,&QPushButton::pressed, ui->screen, &Screen::incPixSize);
    connect(ui->decPixSz,&QPushButton::pressed, ui->screen, &Screen::decPixSize);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showLoc(QPoint loc) {
    ui->location->setText(QString("X: ") + QString::number(loc.x()) + QString(" ")
                          + QString("Y: ") + QString::number(loc.y()));
}

void MainWindow::paint()
{
    bool fill = false;
    vector<QPoint> toDraw;
    chrono::high_resolution_clock::time_point start;
    long timediff;
    if(ui->line_dda->isChecked()) {
        QPoint tmp1 = queue.get();
        QPoint tmp2 = queue.get();
        start = chrono::high_resolution_clock::now();
        toDraw = Line::drawDDA(tmp1, tmp2);
        timediff = chrono::duration_cast<chrono::nanoseconds>
                (chrono::high_resolution_clock::now() - start).count();
    } else if (ui->line_ba->isChecked()) {
        QPoint tmp1 = queue.get();
        QPoint tmp2 = queue.get();
        start = chrono::high_resolution_clock::now();
        toDraw = Line::drawDDA(tmp1, tmp2);
        timediff = chrono::duration_cast<chrono::nanoseconds>
                (chrono::high_resolution_clock::now() - start).count();
    } else if (ui->circle_s->isChecked()) {
        QPoint tmp1 = queue.get();
        QPoint tmp2 = queue.get();
        start = chrono::high_resolution_clock::now();
        toDraw = Circle::drawSimple(tmp1, abs(tmp2.x() - tmp1.x()));
        timediff = chrono::duration_cast<chrono::nanoseconds>
                (chrono::high_resolution_clock::now() - start).count();
    } else if (ui->circle_p->isChecked()) {
        QPoint tmp1 = queue.get();
        QPoint tmp2 = queue.get();
        start = chrono::high_resolution_clock::now();
        toDraw = Circle::drawPolar(tmp1, abs(tmp2.x() - tmp1.x()));
        timediff = chrono::duration_cast<chrono::nanoseconds>
                (chrono::high_resolution_clock::now() - start).count();
    } else if (ui->circle_b->isChecked()) {
        QPoint tmp1 = queue.get();
        QPoint tmp2 = queue.get();
        start = chrono::high_resolution_clock::now();
        toDraw = Circle::drawBresh(tmp1, abs(tmp2.x() - tmp1.x()));
        timediff = chrono::duration_cast<chrono::nanoseconds>
                (chrono::high_resolution_clock::now() - start).count();
    } else if (ui->ellipse_m->isChecked()) {
        QPoint tmp1 = queue.get();
        QPoint tmp2 = queue.get();
        QPoint tmp3 = queue.get();
        start = chrono::high_resolution_clock::now();
        toDraw = Ellipse::drawMidpoint(tmp1, abs(tmp2.x() - tmp1.x()), abs(tmp3.y() - tmp1.y()));
        timediff = chrono::duration_cast<chrono::nanoseconds>
                (chrono::high_resolution_clock::now() - start).count();
    } else if (ui->flood_f->isChecked()) {
        start = chrono::high_resolution_clock::now();
        toDraw = Fill::flood(queue.get(), ui->screen);
        timediff = chrono::duration_cast<chrono::nanoseconds>
                (chrono::high_resolution_clock::now() - start).count();
        fill = true;
    } else if (ui->scan_f->isChecked()) {
        vector<QPoint> points;

        while(!queue.isEmpty()) {
            points.push_back(queue.get());
        }

        start = chrono::high_resolution_clock::now();
        toDraw = Fill::polyfill(points);
        timediff = chrono::duration_cast<chrono::nanoseconds>
                (chrono::high_resolution_clock::now() - start).count();
        fill = true;
    }

    for (uint64_t i = 0; i < toDraw.size(); i++) {
        if (fill == true) {
            ui->screen->colorPixel(toDraw[i]);
        } else {
            ui->screen->setPixel(toDraw[i]);
        }
        delay();
    }

    showExecTime(timediff);
}

void MainWindow::showExecTime(uint64_t milliseconds)
{
    ui->time->setText(QString(QString::number(milliseconds))+QString(" ns"));
}

