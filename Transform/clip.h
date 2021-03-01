#ifndef CLIP_H
#define CLIP_H

#include <QPoint>
#include <vector>

using namespace std;

// Works only when the vertices of
// clipping window is clockwise
class Clip
{
public:
    static vector<QPoint> suthHodg(const vector<QPoint>& polygon, const vector<QPoint>& window);
    static vector<QPoint> cyrusBeck(const vector<QPoint>& points, const vector<QPoint>& window);
private:
    // Find the intersection of 2 lines
    static QPoint intersect(QPoint p1, QPoint p2, QPoint k1, QPoint k2);
    static vector<QPoint> clipEdge (const vector<QPoint>& vertices, QPoint p1, QPoint p2);
    static int dot (pair<int, int> v1, pair<int, int> v2);
};

#endif // CLIP_H
