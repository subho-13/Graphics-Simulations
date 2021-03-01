#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <QPointF>
#include <vector>
#include <string>
#include <cmath>

#include "line.h"

using namespace std;

class Transform
{
public:
    enum Op {
        MOVEUP, MOVEDOWN, MOVELEFT, MOVERIGHT,
        SCALEUP, SCALEDOWN, RCLOCK, RANTI,
        REFLECTX, REFLECTY, SHEARX, SHEARY
    };

    Transform(float dx, float ds, float dt);

    vector<QPointF> moveUp(const vector<QPointF>& points);
    vector<QPointF> moveDown(const vector<QPointF>& points);
    vector<QPointF> moveLeft(const vector<QPointF>& points);
    vector<QPointF> moveRight(const vector<QPointF>& points);

    vector<QPointF> scaleUp(const vector<QPointF>& points);
    vector<QPointF> scaleDown(const vector<QPointF>& points);

    vector<QPointF> clock(const vector<QPointF>& points);
    vector<QPointF> anti(const vector<QPointF>& points);

    vector<QPointF> reflectX(const vector<QPointF>& points);
    vector<QPointF> shearX(const vector<QPointF>& points);

    vector<QPointF> reflectY(const vector<QPointF>& points);
    vector<QPointF> shearY(const vector<QPointF>& points);

    vector<QPointF> compose(const vector<QPointF>& points, vector<Op> ops);

    vector<QPointF> recentre (const vector<QPointF>& points, QPoint loc);
    vector<QPointF> rotate(const vector<QPointF>& points, float angle);


private:
    float   dx;
    float   dtheta;
    float   dscale;

    float dxUp[3][3];
    float dxDown[3][3];
    float dxLeft[3][3];
    float dxRight[3][3];

    float dscaleUp[3][3];
    float dscaleDown[3][3];

    float dthetaClock[3][3];
    float dthetaAnti[3][3];

    float xReflect[3][3];
    float yReflect[3][3];

    float xShear[3][3];
    float yShear[3][3];

    QPointF multiply(float arr[3][3], QPointF point);
    void mMultiply(float arr1[3][3], float arr2[3][3]);
};

#endif // TRANSFORM_H
