#include "bresenham.h"


vector<QPoint> Bresenham::line(QPoint start, QPoint end)
{
    vector<QPoint> points;
    QPoint tmp;

    int x = start.x();
    int y = start.y();

    int dx = abs(end.x() - start.x());
    int dy = abs(end.y() - start.y());

    int s1 = sign(end.x() - start.x());
    int s2 = sign(end.y() - start.y());

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

int Bresenham::sign(int x)
{
    if(x < 0) {
        return -1;
    } else if (x > 0) {
        return 1;
    }

    return 0;
}
