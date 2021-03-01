#include "window.h"

Window::Window(const vector<QPoint> &vertices)
{
    this->vertices = vertices;

    int n = vertices.size();

    for(int i = 0; i < n-1; i++) {
        addEdge(vertices[i], vertices[i+1]);
    }

    addEdge(vertices[n-1], vertices[0]);
}

vector<QPoint> Window::getVertices()
{
    return vertices;
}

vector<QPoint> Window::getPoints()
{
    return points;
}

void Window::addEdge(QPoint p1, QPoint p2)
{
    vector<QPoint> ePoints = Bresenham::line(p1, p2);

    for(uint64_t i = 0; i < ePoints.size()-1; i++) {
        points.push_back(ePoints[i]);
    }
}
