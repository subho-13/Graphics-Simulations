#ifndef LINE_H
#define LINE_H

#include <QPoint>
#include <vector>
using namespace std;

#include <bresenham.h>

class Line
{
public:
    Line(QPoint start, QPoint end);
    vector<QPoint> getPoints() const;
    float getC() const;
    float getM() const;
private:
    QPoint start;
    QPoint end;
    float c;
    float m;
    vector<QPoint> points;
};

#endif // LINE_H
