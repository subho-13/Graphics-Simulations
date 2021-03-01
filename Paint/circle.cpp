#include "circle.h"

vector<QPoint> Circle::drawSimple(QPoint loc, int r)
{
    float y;
    vector<QPoint> points;
    QPoint tmp;
    for(int x = -1*r; x <= r; x++) {
        y = sqrt(r*r - x*x);
        tmp.setX(x); tmp.setY((int)(y+0.5));
        points.push_back(tmp);
        tmp.setX(x); tmp.setY(-1*(int)(y+0.5));
        points.push_back(tmp);
    }

    for(int x = -1*r; x <= r; x++) {
        y = sqrt(r*r - x*x);
        tmp.setX((int)(y+0.5)); tmp.setY(x);
        points.push_back(tmp);
        tmp.setX(-1*(int)(y+0.5)); tmp.setY(x);
        points.push_back(tmp);
    }

    for(uint64_t i = 0; i < points.size(); i++) {
        points[i] += loc;
    }

    return points;
}

vector<QPoint> Circle::drawPolar(QPoint loc, int r)
{
    float x, y;

    vector<QPoint> points;
    QPoint tmp;

    for(float i = 0; i <= 45; i += 180/(3.14159*r)) {
        y = r*sin(i*3.14159/180);
        x = r*cos(i*3.14159/180);

        tmp.setX((int)(x+0.5)); tmp.setY((int)(y+0.5));
        points.push_back(tmp);
    }

    int tsize = points.size();

    for(int i = 0; i < tsize; i++) {
        tmp.setX(points [i].y());
        tmp.setY(points[i].x());
        points.push_back(tmp);
    }

    tsize = points.size();

    for(int i = 0; i < tsize; i++) {
        tmp = points[i];
        tmp.setX(points[i].x()*-1);
        points.push_back(tmp);
        tmp.setY(points[i].y()*-1);
        points.push_back(tmp);
        tmp.setX(points[i].x());
        points.push_back(tmp);
    }

    for(uint64_t i = 0; i < points.size(); i++) {
        points[i] += loc;
    }

    return points;
}

vector<QPoint> Circle::drawBresh(QPoint loc, int r)
{
    vector<QPoint> points;
    QPoint tmp;
    int x = 0;
    int y = r;
    int d = (1-r);

    while(y >= x) {
        tmp.setX(x); tmp.setY(y);
        points.push_back(tmp);

        if(d < 0) {
            x = x + 1;
            d = d + 2*x + 1;
        } else {
            x = x + 1;
            y = y - 1;
            d = d + 2*x + 1 - 2*y;
        }
    }

    int tsize = points.size();

    for(int i = 0; i < tsize; i++) {
        tmp.setX(points [i].y());
        tmp.setY(points[i].x());
        points.push_back(tmp);
    }

    tsize = points.size();

    for(int i = 0; i < tsize; i++) {
        tmp = points[i];
        tmp.setX(points[i].x()*-1);
        points.push_back(tmp);
        tmp.setY(points[i].y()*-1);
        points.push_back(tmp);
        tmp.setX(points[i].x());
        points.push_back(tmp);
    }

    for(uint64_t i = 0; i < points.size(); i++) {
        points[i] += loc;
    }

    return points;
}
