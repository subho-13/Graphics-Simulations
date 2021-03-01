#include "pointq.h"

QPoint PointQ::pop()
{
    QPoint tmp;
    tmp.setX(0); tmp.setY(0);

    if(!points.empty()) {
        tmp = points.front();
        points.pop();
    }

    return tmp;
}

bool PointQ::empty()
{
    return points.empty();
}

void PointQ::reset()
{
    queue<QPoint> empty;
    swap(points, empty);
}

void PointQ::push(QPoint point)
{
    points.push(point);
}

