#include "polygon.h"

Polygon::Polygon(const vector<QPointF> &vertices)
{
    this->vertices = vertices;

    int n = vertices.size();

    for(int i = 0; i < n-1; i++) {
        addEdge(vertices[i].toPoint(), vertices[i+1].toPoint());
    }

    if(n > 2) {
        addEdge(vertices[n-1].toPoint(), vertices[0].toPoint());
    } else {
        points.push_back(vertices[n-1].toPoint());
    }
}

vector<QPointF> Polygon::getVertices() const
{
    return vertices;
}

vector<QPoint> Polygon::getPoints() const
{
    return points;
}

void Polygon::addEdge(QPoint p1, QPoint p2)
{
    vector<QPoint> ePoints = Bresenham::line(p1, p2);

    for(uint64_t i = 0; i < ePoints.size()-1; i++) {
        points.push_back(ePoints[i]);
    }
}
