#ifndef LINE_H
#define LINE_H

#include <QPoint>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

class Line
{
    static int sign(int x);
public:
    static vector<QPoint> drawDDA(QPoint a, QPoint b);
    static vector<QPoint> drawBA(QPoint a, QPoint b);
};

#endif // LINE_H
