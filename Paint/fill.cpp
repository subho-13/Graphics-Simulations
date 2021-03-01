#include "fill.h"

bool Fill::isOk(QPoint loc, int xmax, int xmin, int ymax, int ymin)
{
    if (loc.x() > xmax || loc.x() < xmin || loc.y() > ymax || loc.y() < ymin) {
        return false;
    }

    return true;
}

vector<QPoint> Fill::flood (QPoint loc, Screen *screen)
{
    int xmax, xmin, ymax, ymin;
    screen->getDimensions(xmin, ymin, xmax, ymax);

    vector<QPoint> points;

    if (!isOk(loc, xmax, xmin, ymax, ymin)) {
        return points;
    }

    stack<QPoint> pointsNotDone;
    set<pair<int, int>> alreadyPainted;
    pointsNotDone.push(loc);
    QPoint tmp;
    while(!pointsNotDone.empty()) {
        loc = pointsNotDone.top();
        pointsNotDone.pop();
        if(!screen->isPixelSet(loc) &&
                alreadyPainted.find(make_pair(loc.x(), loc.y())) == alreadyPainted.end()) {
            points.push_back(loc);

            tmp.setX(loc.x()+1);
            tmp.setY(loc.y());

            alreadyPainted.insert(make_pair(loc.x(), loc.y()));

            if (isOk(tmp, xmax, xmin, ymax, ymin)) {
                pointsNotDone.push(tmp);
            }

            tmp.setX(loc.x()-1);
            if (isOk(tmp, xmax, xmin, ymax, ymin)) {
                pointsNotDone.push(tmp);
            }

            tmp.setX(loc.x());
            tmp.setY(loc.y()+1);
            if (isOk(tmp, xmax, xmin, ymax, ymin)) {
                pointsNotDone.push(tmp);
            }

            tmp.setY(loc.y()-1);
            if (isOk(tmp, xmax, xmin, ymax, ymin)) {
                pointsNotDone.push(tmp);
            }
        }
    }

    return points;
}

vector<QPoint> Fill::polyfill(vector<QPoint> vertices)
{
    Polygon polygon(vertices);
    return polygon.fill();
}
