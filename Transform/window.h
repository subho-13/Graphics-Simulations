#ifndef WINDOW_H
#define WINDOW_H

#include <QPoint>
#include<vector>

using namespace std;

#include "bresenham.h"

class Window
{
public:
    Window(const vector<QPoint>& vertices);
    vector<QPoint> getPoints();
    vector<QPoint> getVertices();
private:
    vector<QPoint> vertices;
    vector<QPoint> points;

    void addEdge(QPoint p1, QPoint p2);
};

#endif // WINDOW_H
