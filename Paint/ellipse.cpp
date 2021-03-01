#include "ellipse.h"

vector<QPoint> Ellipse::drawMidpoint(QPoint loc, int a, int b)
{
    vector<QPoint> points;
    QPoint tmp;

    // Initialising variables
    int x = a + 0.5;
    int y = 0;

    // define tmp variables
    int taa = a*a;
    int t2aa = 2*taa;
    int t4aa = 2*t2aa;

    int tbb = b*b;
    int t2bb = 2*tbb;
    int t4bb = 2*t2bb;

    int t2bbx = t2bb*x;
    int tx = x;

    // initialize the decision variable in region 1
    int d1 = t2bbx*(x-1) + tbb/2 + t2aa*(1-tbb);

    while (t2bb*x > t2aa*y) {
        tmp.setX(x); tmp.setY(y);
        points.push_back(tmp);

        if(d1 < 0) {
            y = y + 1;
            d1 = d1 + t4aa*y + t2aa;
            // tx = x - 1;
        }
        else {
            x = x - 1;
            y = y + 1;
            d1 = d1 - t4bb*x + t4aa*y + t2aa;
            // tx = x;
        }
    }

    // initialize the decision variable in region 2
    int d2 = t2bb*(x*x + 1) - t4bb*x + t2aa*(y*y + y - tbb) + taa/2;

    while(x >= 0) {
        tmp.setX(x); tmp.setY(y);
        points.push_back(tmp);

        if (d2 < 0) {
            x = x - 1;
            y = y + 1;
            d2 = d2 + t4aa*y - t4bb*x + t2bb;
        } else {
            x = x - 1;
            d2 = d2 - t4bb*x + t2bb;
        }
    }

    // Reflect point about x axis
    int tsize = points.size();

    for(int i = 0; i < tsize; i++) {
        tmp = points[i];
        tmp.setY(tmp.y()*-1);
        points.push_back(tmp);
    }

    // Reflect point about y axis
    tsize = points.size();

    for(int i = 0; i < tsize; i++) {
        tmp = points[i];
        tmp.setX(tmp.x()*-1);
        points.push_back(tmp);
    }

    for(uint64_t i = 0; i < points.size(); i++) {
        points[i] += loc;
    }

    return points;
}
