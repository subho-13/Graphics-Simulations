#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , transform(DX, DSCALE, DTHETA)
{
    ui->setupUi(this);

    connect(ui->reset, &QPushButton::pressed, this, &MainWindow::reset);
    connect(ui->changeColor, &QPushButton::pressed, ui->screen, &Screen::changeColor);
    connect(ui->sizeUp, &QPushButton::pressed, this, &MainWindow::incGridSize);
    connect(ui->sizeDown, &QPushButton::pressed, this, &MainWindow::decGridSize);
    connect(ui->screen, &Screen::sendLoc, this, &MainWindow::addPoint);
    connect(ui->delay, &QPushButton::pressed, this, &MainWindow::switchDelay);


    connect(ui->line, &QPushButton::pressed, this, &MainWindow::line);
    connect(ui->polygon, &QPushButton::pressed, this, &MainWindow::polygon);
    connect(ui->pivot, &QPushButton::pressed, this, &MainWindow::pivot);
    connect(ui->window, &QPushButton::pressed, this, &MainWindow::window);

    connect(ui->up, &QPushButton::pressed, this, &MainWindow::moveUp);
    connect(ui->left, &QPushButton::pressed, this, &MainWindow::moveLeft);
    connect(ui->right, &QPushButton::pressed, this, &MainWindow::moveRight);
    connect(ui->down, &QPushButton::pressed, this, &MainWindow::moveDown);

    connect(ui->anticlock, &QPushButton::pressed, this, &MainWindow::rotateAnti);
    connect(ui->clock, &QPushButton::pressed, this, &MainWindow::rotateClock);

    connect(ui->scaleUp, &QPushButton::pressed, this, &MainWindow::scaleUp);
    connect(ui->scaleDown, &QPushButton::pressed, this, &MainWindow::scaleDown);

    connect(ui->reflect, &QPushButton::pressed, this, &MainWindow::reflect);
    connect(ui->shear, &QPushButton::pressed, this, &MainWindow::shear);

    connect(ui->repaint, &QPushButton::pressed, this, &MainWindow::repaint);
    connect(ui->clip, &QPushButton::pressed, this, &MainWindow::clip);
}

void MainWindow::setPixels(const vector<QPoint> &points)
{
    for(QPoint tmp : points) {
        if(toDelay) { delay(DELAY); }
        ui->screen->setPixel(tmp);
    }
}

void MainWindow::setPixels(const vector<QPoint> &points, QColor color)
{
    ui->screen->useColor(color);
    setPixels(points);
    ui->screen->restoreColor();
}

void MainWindow::unsetPixels(const vector<QPoint> &points)
{
    for(QPoint tmp: points) {
        if(toDelay) { delay(DELAY); }
        ui->screen->unsetPixel(tmp);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reset()
{
    if(toDelay == true) {
        switchDelay();
    }
    pointQ.reset();
    lines.clear();
    polygons.clear();
    windows.clear();
    ui->screen->reset();
}

void MainWindow::line()
{
    vector<QPoint> vertices;

    while(vertices.size() < 2 && !pointQ.empty()) {
        vertices.push_back(pointQ.pop());
    }

    if(vertices.size() == 0) {
        for(Line tmp: lines) {
            unsetPixels(tmp.getPoints());
        }
        lines.clear();
        return;
    }

    if (vertices.size() != 2) {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","2 points required");
        messageBox.setFixedSize(500,200);
        unsetPixels(vertices);
        return;
    }

    Line tmp(vertices[0], vertices[1]);
    lines.push_back(tmp);
    setPixels(tmp.getPoints(), QColor(LINECLR));
}

void MainWindow::polygon()
{
    vector<QPointF> vertices;

    while(!pointQ.empty()) {
        vertices.push_back(pointQ.pop());
    }

    if (vertices.size() == 0) {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","No points were provided");
        messageBox.setFixedSize(500,200);
        return;
    }

    Polygon tmp(vertices);
    polygons.push_back(tmp);
    setPixels(tmp.getPoints());
}

void MainWindow::pivot()
{
    vector<QPoint> vertices;

    while(vertices.size() < 1 && !pointQ.empty()) {
        vertices.push_back(pointQ.pop());
    }

    if (vertices.size() == 0) {
        unsetPixels(pivots);
        pivots.clear();
        return;
    }

    pivots.push_back(vertices[0]);
    setPixels(vertices, QColor(PIVOTCLR));
}

void MainWindow::window()
{
    vector<QPoint> vertices;

    while(!pointQ.empty()) {
        vertices.push_back(pointQ.pop());
    }

    if(vertices.size() == 0) {
        for(Window tmp: windows) {
            unsetPixels(tmp.getPoints());
        }
        windows.clear();
        return;
    }

    if (vertices.size() < 3) {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","At least 3 points required");
        messageBox.setFixedSize(500,200);
        unsetPixels(vertices);
        return;
    }

    Window window(vertices);
    windows.push_back(window);
    setPixels(window.getPoints(), QColor(WINDOWCLR));
}

void MainWindow::switchDelay()
{
    toDelay = !toDelay;

    if(toDelay == false) {
        ui->delay->setStyleSheet("QPushButton {"
                                 "font: 20pt Fira Code;"
                                 "color: #ffa631;"
                                 "border-width: 2px;"
                                 "border-style: solid;"
                                 "border-color: #cbc2c4;"
                                 "background-color: #080808 ;"
                                 "}");

        ui->up->setAutoRepeat(true);
        ui->left->setAutoRepeat(true);
        ui->right->setAutoRepeat(true);
        ui->down->setAutoRepeat(true);
        ui->scaleDown->setAutoRepeat(true);
        ui->scaleUp->setAutoRepeat(true);
        ui->shear->setAutoRepeat(true);
        ui->anticlock->setAutoRepeat(true);
        ui->clock->setAutoRepeat(true);
    } else {
        ui->delay->setStyleSheet("QPushButton {"
                                 "font: 25pt Fira Code;"
                                 "color: #080808;"
                                 "border-width: 2px;"
                                 "border-style: solid;"
                                 "border-color: #242c2b;"
                                 "background-color: #ffa631 ;"
                                 "}");

        ui->up->setAutoRepeat(false);
        ui->left->setAutoRepeat(false);
        ui->right->setAutoRepeat(false);
        ui->down->setAutoRepeat(false);
        ui->scaleDown->setAutoRepeat(false);
        ui->scaleUp->setAutoRepeat(false);
        ui->shear->setAutoRepeat(false);
        ui->anticlock->setAutoRepeat(false);
        ui->clock->setAutoRepeat(false);
    }
}

void MainWindow::addPoint(QPoint loc)
{
    ui->location->setText(QString::number(loc.x()) + ", " + QString::number(loc.y()));
    pointQ.push(loc);
}

void MainWindow::moveUp()
{
    vector<QPointF> tmpVertices;

    for(uint64_t i = 0; i < polygons.size(); i++) {
        tmpVertices = polygons[i].getVertices();
        Polygon tmpPolygon(transform.moveUp(tmpVertices));
        unsetPixels(polygons[i].getPoints());
        polygons[i] = tmpPolygon;
        setPixels(tmpPolygon.getPoints());
    }
}

void MainWindow::moveDown()
{
    vector<QPointF> tmpVertices;

    for(uint64_t i = 0; i < polygons.size(); i++) {
        tmpVertices = polygons[i].getVertices();
        Polygon tmpPolygon(transform.moveDown(tmpVertices));
        unsetPixels(polygons[i].getPoints());
        polygons[i] = tmpPolygon;
        setPixels(tmpPolygon.getPoints());
    }
}

void MainWindow::moveLeft()
{
    vector<QPointF> tmpVertices;

    for(uint64_t i = 0; i < polygons.size(); i++) {
        tmpVertices = polygons[i].getVertices();
        Polygon tmpPolygon(transform.moveLeft(tmpVertices));

        unsetPixels(polygons[i].getPoints());
        polygons[i] = tmpPolygon;
        setPixels(tmpPolygon.getPoints());
    }
}

void MainWindow::moveRight()
{
    vector<QPointF> tmpVertices;

    for(uint64_t i = 0; i < polygons.size(); i++) {
        tmpVertices = polygons[i].getVertices();
        Polygon tmpPolygon(transform.moveRight(tmpVertices));
        unsetPixels(polygons[i].getPoints());
        polygons[i] = tmpPolygon;
        setPixels(tmpPolygon.getPoints());
    }
}

void MainWindow::rotateAnti()
{
    if(pivots.size() == 0) {
        vector<QPointF> tmpVertices;

        for(uint64_t i = 0; i < polygons.size(); i++) {
            tmpVertices = polygons[i].getVertices();
            Polygon tmpPolygon(transform.anti(tmpVertices));
            unsetPixels(polygons[i].getPoints());
            polygons[i] = tmpPolygon;
            setPixels(tmpPolygon.getPoints());
        }
    } else {
        for(QPoint pivot: pivots) {
            vector<QPointF> tmpVertices;

            for(uint64_t i = 0; i < polygons.size(); i++) {
                Polygon tmpPolygon(rotatePivotAnti(polygons[i], pivot));
                unsetPixels(polygons[i].getPoints());
                polygons[i] = tmpPolygon;
                setPixels(tmpPolygon.getPoints());
            }
        }
    }
}

void MainWindow::rotateClock()
{
    if(pivots.size() == 0) {
        vector<QPointF> tmpVertices;

        for(uint64_t i = 0; i < polygons.size(); i++) {
            tmpVertices = polygons[i].getVertices();
            Polygon tmpPolygon(transform.clock(tmpVertices));
            unsetPixels(polygons[i].getPoints());
            polygons[i] = tmpPolygon;
            setPixels(tmpPolygon.getPoints());
        }
    } else {
        for(QPoint pivot: pivots) {
            vector<QPointF> tmpVertices;

            for(uint64_t i = 0; i < polygons.size(); i++) {
                Polygon tmpPolygon(rotatePivotClock(polygons[i], pivot));
                unsetPixels(polygons[i].getPoints());
                polygons[i] = tmpPolygon;
                setPixels(tmpPolygon.getPoints());
            }
        }
    }
}

void MainWindow::scaleUp()
{
    if(pivots.size() == 0) {
        vector<QPointF> tmpVertices;

        for(uint64_t i = 0; i < polygons.size(); i++) {
            tmpVertices = polygons[i].getVertices();
            Polygon tmpPolygon(transform.scaleUp(tmpVertices));
            unsetPixels(polygons[i].getPoints());
            polygons[i] = tmpPolygon;
            setPixels(tmpPolygon.getPoints());
        }
    } else {
        for(QPoint pivot: pivots) {
            vector<QPointF> tmpVertices;

            for(uint64_t i = 0; i < polygons.size(); i++) {
                Polygon tmpPolygon(scalePivotUp(polygons[i], pivot));
                unsetPixels(polygons[i].getPoints());
                polygons[i] = tmpPolygon;
                setPixels(tmpPolygon.getPoints());
            }
        }
    }
}

void MainWindow::scaleDown()
{
    if(pivots.size() == 0) {
        vector<QPointF> tmpVertices;

        for(uint64_t i = 0; i < polygons.size(); i++) {
            tmpVertices = polygons[i].getVertices();
            Polygon tmpPolygon(transform.scaleDown(tmpVertices));
            unsetPixels(polygons[i].getPoints());
            polygons[i] = tmpPolygon;
            setPixels(tmpPolygon.getPoints());
        }
    } else {
        for(QPoint pivot: pivots) {
            vector<QPointF> tmpVertices;

            for(uint64_t i = 0; i < polygons.size(); i++) {
                Polygon tmpPolygon(scalePivotDown(polygons[i], pivot));
                unsetPixels(polygons[i].getPoints());
                polygons[i] = tmpPolygon;
                setPixels(tmpPolygon.getPoints());
            }
        }
    }
}

void MainWindow::reflect()
{
    if(lines.size() == 0 && pivots.size() == 0) {
        vector<QPointF> tmpVertices;

        for(uint64_t i = 0; i < polygons.size(); i++) {
            tmpVertices = polygons[i].getVertices();
            Polygon tmpPolygon(
                        transform.reflectY(
                        transform.reflectX(tmpVertices)
                        ));
            unsetPixels(polygons[i].getPoints());
            polygons[i] = tmpPolygon;
            setPixels(tmpPolygon.getPoints());
        }
    }

    if(pivots.size() != 0) {
        for(QPoint pivot: pivots) {
            vector<QPointF> tmpVertices;

            for(uint64_t i = 0; i < polygons.size(); i++) {
                Polygon tmpPolygon(reflectPivot(polygons[i], pivot));
                unsetPixels(polygons[i].getPoints());
                polygons[i] = tmpPolygon;
                setPixels(tmpPolygon.getPoints());
            }
        }
    }

    if(lines.size() != 0) {
        for(Line line: lines) {
            vector<QPointF> tmpVertices;

            for(uint64_t i = 0; i < polygons.size(); i++) {
                Polygon tmpPolygon(reflectLine(polygons[i], line));
                unsetPixels(polygons[i].getPoints());
                polygons[i] = tmpPolygon;
                setPixels(tmpPolygon.getPoints());
            }
        }
    }
}

void MainWindow::shear()
{
    if(lines.size() == 0 ) {
        vector<QPointF> tmpVertices;

        for(uint64_t i = 0; i < polygons.size(); i++) {
            tmpVertices = polygons[i].getVertices();
            Polygon tmpPolygon(transform.shearX(tmpVertices));
            unsetPixels(polygons[i].getPoints());
            polygons[i] = tmpPolygon;
            setPixels(tmpPolygon.getPoints());
        }
    }

    for(Line line: lines) {
        vector<QPointF> tmpVertices;

        for(uint64_t i = 0; i < polygons.size(); i++) {
            Polygon tmpPolygon(shearLine(polygons[i], line));
            unsetPixels(polygons[i].getPoints());
            polygons[i] = tmpPolygon;
            setPixels(tmpPolygon.getPoints());
        }
    }
}

void MainWindow::repaint()
{
    for(Line line: lines) {
        setPixels(line.getPoints(), LINECLR);
    }

    setPixels(pivots, PIVOTCLR);

    for(Window window: windows) {
        setPixels(window.getPoints(), WINDOWCLR);
    }

    for(Polygon polygon: polygons) {
        setPixels(polygon.getPoints());
        ui->screen->changeColor();
    }
}

void MainWindow::clip()
{
    vector<QPoint> tmp;
    vector<QPointF> tmpF;
    for(Window window: windows) {
        for(uint64_t i = 0; i < polygons.size(); i++) {
            tmpF = polygons[i].getVertices();
            tmp.resize(tmpF.size());

            for(uint i = 0; i < tmpF.size(); i++) {
                tmp[i] = tmpF[i].toPoint();
            }

            if(tmp.size() <= 2) {
                tmp = Clip::cyrusBeck(tmp, window.getVertices());
            } else {
                tmp = Clip::suthHodg(tmp, window.getVertices());
            }

            tmpF = convQPointVec(tmp);

            Polygon tmpPolygon(tmpF);
            unsetPixels(polygons[i].getPoints());
            polygons[i] = tmpPolygon;
            setPixels(tmpPolygon.getPoints());
        }
    }
}

void MainWindow::incGridSize()
{
    ui->screen->incSize();
    reset();
}

void MainWindow::decGridSize()
{
    ui->screen->decSize();
    reset();
}

void MainWindow::delay(int ms)
{
    QTime dieTime= QTime::currentTime().addMSecs(ms);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 1);
}

vector<QPointF> MainWindow::convQPointVec(const vector<QPoint> &points)
{
    QPointF tmpF;
    vector<QPointF> fPoints;

    for(QPoint tmp: points) {
        tmpF = tmp;
        fPoints.push_back(tmpF);
    }

    return fPoints;
}

float MainWindow::convDegreeRadian(float angle)
{
    return PI*angle/180;
}

Polygon MainWindow::rotatePivotAnti(const Polygon &p, QPoint pivot)
{
    Polygon tmp1(transform.recentre(p.getVertices(), pivot));
    Polygon tmp2(transform.anti(tmp1.getVertices()));
    Polygon tmp3(transform.recentre(tmp2.getVertices(), -1*pivot));
    return tmp3;
}

Polygon MainWindow::rotatePivotClock(const Polygon &p, QPoint pivot)
{
    Polygon tmp1(transform.recentre(p.getVertices(), pivot));
    Polygon tmp2(transform.clock(tmp1.getVertices()));
    Polygon tmp3(transform.recentre(tmp2.getVertices(), -1*pivot));
    return tmp3;
}

Polygon MainWindow::scalePivotUp(const Polygon &p, QPoint pivot)
{
    Polygon tmp1(transform.recentre(p.getVertices(), pivot));
    Polygon tmp2(transform.scaleUp(tmp1.getVertices()));
    Polygon tmp3(transform.recentre(tmp2.getVertices(), -1*pivot));
    return tmp3;
}

Polygon MainWindow::scalePivotDown(const Polygon &p, QPoint pivot)
{
    Polygon tmp1(transform.recentre(p.getVertices(), pivot));
    Polygon tmp2(transform.scaleDown(tmp1.getVertices()));
    Polygon tmp3(transform.recentre(tmp2.getVertices(), -1*pivot));
    return tmp3;
}

Polygon MainWindow::reflectPivot(const Polygon &p, QPoint pivot)
{
    Polygon tmp1(transform.recentre(p.getVertices(), pivot));
    Polygon tmp2(transform.reflectX(tmp1.getVertices()));
    Polygon tmp3(transform.reflectY(tmp1.getVertices()));
    Polygon tmp4(transform.recentre(tmp2.getVertices(), -1*pivot));
    return tmp4;
}

Polygon MainWindow::reflectLine(const Polygon &p, const Line& line)
{
    float angle = atan(line.getM());
    QPoint pivot(0, line.getC());

    Polygon tmp1(transform.recentre(p.getVertices(), pivot));
    Polygon tmp2(transform.rotate(tmp1.getVertices(), angle));

    Polygon tmp3(transform.reflectX(tmp2.getVertices()));

    Polygon tmp4(transform.rotate(tmp3.getVertices(), -1*angle));
    Polygon tmp5(transform.recentre(tmp4.getVertices(), -1*pivot));
    return  tmp5;
}

Polygon MainWindow::shearLine(const Polygon &p, const Line &line)
{
    float angle = atan(line.getM());
    QPoint pivot(0, line.getC());

    Polygon tmp1(transform.recentre(p.getVertices(), pivot));
    Polygon tmp2(transform.rotate(tmp1.getVertices(), angle));

    Polygon tmp3(transform.shearX(tmp2.getVertices()));

    Polygon tmp4(transform.rotate(tmp3.getVertices(), -1*angle));
    Polygon tmp5(transform.recentre(tmp4.getVertices(), -1*pivot));

    return  tmp5;
}

