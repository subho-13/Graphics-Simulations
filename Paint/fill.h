#ifndef BOUNDARYFILL_H
#define BOUNDARYFILL_H

#include <QPoint>
#include <vector>
#include <stack>
#include <set>

#include "screen.h"
#include "polygon.h"

using namespace std;

class Fill
{
    static bool isOk(QPoint loc, int xmax, int xmin, int ymax, int ymin);
public:
    static vector<QPoint> flood(QPoint loc, Screen* screen);
    static vector<QPoint> polyfill(vector<QPoint> vertices);
};

#endif // BOUNDARYFILL_H
