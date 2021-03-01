#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <vector>
#include <QPoint>

using namespace std;

class Ellipse
{
public:
    static vector<QPoint> drawMidpoint(QPoint loc, int a, int b);
};

#endif // ELLIPSE_H
