#include "polygon.h"

void Polygon::addEdge(int lineNo, QPoint p1, QPoint p2)
{
    vector<QPoint> points(Line::drawBA(p1, p2));

    for(uint64_t i = 0; i < points.size()-1; i++) {
        edgeVertices.push_back(make_pair(points[i], lineNo));
    }
}

bool Polygon::isSpecial(QPoint p)
{
    uint64_t n = vertices.size();
    for(uint64_t i = 0; i < n; i++) {
        if(vertices[i] == p) {
            int val = 1;

            if(i == 0) {
                val = p.y() - vertices[n-1].y();
            } else {
                val = p.y() - vertices[i-1].y();
            }

            if(i == n-1) {
                val *= (p.y() - vertices[0].y());
            } else {
                val *= (p.y() - vertices[i+1].y());
            }

            if (val > 0) {
                return true;
            }

            return false;
        }
    }

    return false;
}

bool Polygon::cmp(pair<QPoint, int> p1, pair<QPoint, int> p2)
{
    if(p1.first.y() < p2.first.y()) {
        return true;
    }

    if(p1.first.y() == p2.first.y()) {
        if(p1.first.x() < p2.first.x()) {
            return true;
        }
    }

    return false;
}

bool Polygon::isVertex(QPoint p) {
    for(uint64_t i = 0; i < vertices.size(); i++) {
        if (vertices[i] == p) {
            return true;
        }
    }

    return false;
}

Polygon::Polygon(vector<QPoint> vertices)
{
    for(uint64_t i = 0; i < vertices.size(); i++) {
        this->vertices.push_back(vertices[i]);
    }

    for(uint64_t i = 0; i < vertices.size()-1; i++) {
        addEdge(i, vertices[i], vertices[i+1]);
    }

    addEdge(vertices.size()-1, vertices[vertices.size()-1], vertices[0]);
    sort(edgeVertices.begin(), edgeVertices.end(), cmp);
}

vector<QPoint> Polygon::fill()
{
    vector<pair<QPoint, QPoint>> activePoints;

    int parity = -1;

    for(uint64_t i = 0; i < edgeVertices.size()-1; i++) {
        if(edgeVertices[i].first.y() != edgeVertices[i+1].first.y()) {
            parity = -1;

            continue;
        }

        if(edgeVertices[i].first.x()+1 == edgeVertices[i+1].first.x()) {
            if(edgeVertices[i].second != edgeVertices[i+1].second) {
               if (!(isVertex(edgeVertices[i].first)
                             || isVertex(edgeVertices[i].first))) {
                    parity *= -1;
                    continue;
                }
               continue;
            }

            if (isSpecial(edgeVertices[i].first)) {
                parity *= -1;
            }

            continue;
        }

        if(!isSpecial(edgeVertices[i].first)) {
            parity *= -1;
        }

        if(parity == 1) {
            activePoints.push_back(make_pair(edgeVertices[i].first, edgeVertices[i+1].first));
        }
    }

    vector<QPoint> points;

    for(uint64_t i = 0; i < edgeVertices.size(); i++) {
        points.push_back(edgeVertices[i].first);
    }

    for(uint64_t i = 0; i < activePoints.size(); i++) {
        QPoint tmp = activePoints[i].first;
        tmp.setX(tmp.x()+1);

        while(tmp.x() < activePoints[i].second.x()) {
            points.push_back(tmp);
            tmp.setX(tmp.x()+1);
        }
    }

    return points;
}
