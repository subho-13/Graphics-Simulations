#include "line.h"

int Line::sign(int x) {
    if(x < 0) {
        return -1;
    } else if (x > 0) {
        return 1;
    }

    return 0;
}

vector<QPoint> Line::drawDDA(QPoint a, QPoint b)
{
    vector<QPoint> points;
    QPoint tmp;
    float l;
    if (fabs(a.x() - b.x()) > fabs(a.y() - b.y())) {
        l = fabs(a.x() - b.x());
    } else {
        l = fabs(a.y() - b.y());
    }

    float dx = (b.x() - a.x())/l;
    float dy = (b.y() - a.y())/l;

    float x = a.x() + 0.5;
    float y = a.y() + 0.5;

    for (int i = 1; i <= l; i++) {
        tmp.setX(floor(x)); tmp.setY(floor(y));
        points.push_back(tmp);
        x += dx;
        y += dy;
    }

    tmp.setX(floor(x)); tmp.setY(floor(y));
    points.push_back(tmp);

    return points;
}

vector<QPoint> Line::drawBA(QPoint a, QPoint b)
{
    vector<QPoint> points;
    QPoint tmp;

    int x = a.x();
    int y = a.y();

    int dx = abs(b.x() - a.x());
    int dy = abs(b.y() - a.y());

    int s1 = sign(b.x() - a.x());
    int s2 = sign(b.y() - a.y());

    bool interchange = false;

    if(dy > dx) {
        swap(dy, dx);
        interchange = true;
    }

    int e = 2*dy - dx;

    for(int i = 1; i <= dx; i++) {
        tmp.setX(x); tmp.setY(y);
        points.push_back(tmp);

        if(e > 0) {
            if(interchange) {
                x += s1;
            } else {
                y += s2;
            }

            e = e - 2*dx;
        }

        if(interchange) {
            y += s2;
        } else {
            x += s1;
        }

        e = e + 2*dy;
    }

    tmp.setX(x); tmp.setY(y);
    points.push_back(tmp);

    return points;
}

