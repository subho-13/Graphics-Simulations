#include "clip.h"

vector<QPoint> Clip::suthHodg(const vector<QPoint> &polygon, const vector<QPoint> &vertices)
{
    int winsize = vertices.size();
    vector<QPoint> tmp = polygon;
    for(int i = 0; i < winsize; i++) {
        tmp = clipEdge(tmp, vertices[i], vertices[(i+1)%winsize]);
    }

    return tmp;
}

vector<QPoint> Clip::cyrusBeck(const vector<QPoint> & ppoints, const vector<QPoint> &vertices)
{
    QPoint p1, p2;
    p1 = ppoints[0];
    int m = ppoints.size();
    if(m != 2) {
        p2 = p1;
    } else {
        p2 = ppoints[1];
    }

    int n = vertices.size();

    // Calculating p2 - p1
    pair<int, int> P2_P1
            = make_pair(p2.x() - p1.x(), p2.y() - p1.y());

    // Calculating P1 - Ei
    pair<int, int> P1_Ei;
    pair<int, int> normal;
    int num, den;
    float tu, tl, t;
    tl = 0; tu = 1;

    vector<QPoint> points;

    for (int i = 0; i < n; i++) {
        P1_Ei.first = p1.x() - vertices[i].x();
        P1_Ei.second = p1.y() - vertices[i].y();

        normal.first = vertices[(i+1)%n].y() - vertices[i].y();
        normal.second = vertices[i].x() - vertices[(i+1)%n].x();

        num = dot(P1_Ei, normal);
        den = dot(P2_P1, normal);

        if(den == 0) {
            if (num < 0) {
                return points;
            } else {
                continue;
            }
        }

        t = -1* (float)num/(float)den;
        if(den > 0) {
            if (t > 1) {
                return points;
            }

            tl = max(t, tl);
        } else {
            if (t < 0) {
                return points;
            }
            tu = min(t, tu);
        }
    }

    QPoint tmp;

    if (tl <= tu) {
        tmp.setX((float)p1.x() + (float)tl*(float)P2_P1.first);
        tmp.setY((float)p1.y() + (float)tl*(float)P2_P1.second);
        points.push_back(tmp);
        tmp.setX((float)p1.x() + (float)tu*(float)P2_P1.first);
        tmp.setY((float)p1.y() + (float)tu*(float)P2_P1.second);
        points.push_back(tmp);
    }

    return points;
}

QPoint Clip::intersect(QPoint p1, QPoint p2, QPoint k1, QPoint k2)
{
    int x1 = p1.x(), x2 = p2.x(), x3 = k1.x(), x4 = k2.x();
    int y1 = p1.y(), y2 = p2.y(), y3 = k1.y(), y4 = k2.y();

    QPoint tmp;

    int num1 = (x1*y2 - y1*x2)*(x3-x4) -
               (x1-x2)*(x3*y4 - y3*x4);

    int den = (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4);

    int num2 = (x1*y2 - y1*x2)*(y3-y4) -
               (y1-y2)*(x3*y4 - y3*x4);

    tmp.setX(num1/den);
    tmp.setY(num2/den);

    return tmp;
}

vector<QPoint> Clip::clipEdge(const vector<QPoint> &vertices, QPoint p1, QPoint p2)
{
    vector<QPoint> newVertices;
    int n = vertices.size();

    for(int i = 0; i < n; i++) {
        QPoint q1 = vertices[i];
        QPoint q2 = vertices[(i+1)%n];

        int posQ1 = (p2.x() - p1.x())*(q1.y()-p1.y()) -
                    (p2.y() - p1.y())*(q1.x()-p1.x());

        int posQ2 = (p2.x() - p1.x())*(q2.y()-p1.y()) -
                    (p2.y() - p1.y())*(q2.x()-p1.x());

        // Case 1 : Both points are inside
        if (posQ1 < 0 && posQ2 < 0) {
            newVertices.push_back(q2);
        }
        // Case 2 : When only first point is outside
        else if (posQ1 > 0 && posQ2 < 0) {
            newVertices.push_back(intersect(p1, p2, q1, q2));
            newVertices.push_back(q2);
        }
        // Case 3 : When only second point is outside
        else if (posQ1 < 0 && posQ2 >= 0) {
            newVertices.push_back(intersect(p1, p2, q1, q2));
        }
        // Case 4 : When both points are outside
        else {
            // No points are added
        }
    }

    return newVertices;
}

int Clip::dot(pair<int, int> v1, pair<int, int> v2)
{
    return v1.first*v2.first + v1.second*v2.second;
}
