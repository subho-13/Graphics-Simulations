#include "line.h"

Line::Line(QPoint start, QPoint end)
{
    this->start = start; this->end = end;
    points = Bresenham::line(start, end);

    float x1, x0, y1, y0;
    x1 = end.x(); x0 = start.x();
    y1 = end.y(); y0 = start.y();

    m = (y1 - y0)/(x1 - x0);
    c = y1 - x1*(y1 - y0)/(x1 - x0);
}

vector<QPoint> Line::getPoints() const
{
    return points;
}

float Line::getC() const
{
    return c;
}

float Line::getM() const
{
    return m;
}
