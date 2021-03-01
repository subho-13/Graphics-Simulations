#ifndef BRESENHAM_H
#define BRESENHAM_H

#include <QPoint>
#include <vector>

using namespace std;

class Bresenham
{
public:
    static vector<QPoint> line (QPoint start, QPoint end);
private:
    static int sign(int x);
};

#endif // BRESENHAM_H
