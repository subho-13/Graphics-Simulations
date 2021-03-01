#ifndef POLYGON_H
#define POLYGON_H

#include <QPointF>
#include <vector>

using namespace std;

#include "bresenham.h"

class Polygon
{
public:
    Polygon(const vector<QPointF>& vertices);
    vector<QPointF> getVertices() const;
    vector<QPoint> getPoints() const;
private:
    vector<QPointF> vertices;
    vector<QPoint> points;

    void addEdge(QPoint p1, QPoint p2);
};

#endif // POLYGON_H
