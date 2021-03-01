#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include <QPoint>
#include <line.h>

using namespace std;


class Polygon
{
    vector<QPoint> vertices;
    vector<pair<QPoint, int>> edgeVertices;

    void addEdge(int lineNo, QPoint p1, QPoint p2);
    bool isSpecial(QPoint p);
    bool isVertex(QPoint p);
    static bool cmp(pair<QPoint, int> p1, pair<QPoint, int> p2);
public:
    Polygon(vector<QPoint> vertices);
    vector<QPoint> fill();
};

#endif // POLYGON_H
