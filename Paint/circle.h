#ifndef CIRCLE_H
#define CIRCLE_H

#include <vector>
#include <QPoint>
#include <cmath>


using namespace std;

class Circle
{
public:
    static vector<QPoint> drawSimple (QPoint loc, int r);
    static vector<QPoint> drawPolar (QPoint loc, int r);
    static vector<QPoint> drawBresh (QPoint loc, int r);
};

#endif // CIRCLE_H
