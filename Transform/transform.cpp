#include "transform.h"


Transform::Transform(float dx, float ds, float dt):
    dxUp{{1, 0, 0}, {0, 1, dx}, {0, 0, 1}},
    dxDown{{1, 0, 0}, {0, 1, -1*dx}, {0, 0, 1}},
    dxLeft{{1, 0, -1*dx}, {0, 1, 0}, {0, 0, 1}},
    dxRight{{1, 0, dx}, {0, 1, 0}, {0, 0, 1}},
    dscaleUp{{ds, 0, 0}, {0, ds, 0}, {0, 0, 1}},
    dscaleDown{{1/ds, 0, 0}, {0, 1/ds, 0}, {0, 0, 1}},
    dthetaClock{{cos(dt), sin(dt), 0}, {-1*sin(dt), cos(dt), 0}, {0, 0, 1}},
    dthetaAnti{{cos(dt), -1*sin(dt), 0}, {sin(dt), cos(dt), 0}, {0, 0, 1}},
    xReflect{{1, 0, 0}, {0, -1, 0}, {0, 0 , 1}},
    yReflect{{-1, 0, 0}, {0, 1, 0}, {0, 0 , 1}},
    xShear{{1, tan(dt), 0}, {0, 1, 0}, {0, 0 , 1}},
    yShear{{1, 0, 0}, {tan(dt), 1, 0}, {0, 0 , 1}}
{}

vector<QPointF> Transform::moveUp(const vector<QPointF> &points)
{
    vector<QPointF> updatedP;

    for(QPointF tmp: points) {
        updatedP.push_back(multiply(dxUp, tmp));
    }

    return updatedP;
}

vector<QPointF> Transform::moveDown(const vector<QPointF> &points)
{
    vector<QPointF> updatedP;

    for(QPointF tmp: points) {
        updatedP.push_back(multiply(dxDown, tmp));
    }

    return updatedP;
}

vector<QPointF> Transform::moveLeft(const vector<QPointF> &points)
{
    vector<QPointF> updatedP;

    for(QPointF tmp: points) {
        updatedP.push_back(multiply(dxLeft, tmp));
    }

    return updatedP;
}

vector<QPointF> Transform::moveRight(const vector<QPointF> &points)
{
    vector<QPointF> updatedP;

    for(QPointF tmp: points) {
        updatedP.push_back(multiply(dxRight, tmp));
    }

    return updatedP;
}

vector<QPointF> Transform::scaleUp(const vector<QPointF> &points)
{
    vector<QPointF> updatedP;

    for(QPointF tmp: points) {
        updatedP.push_back(multiply(dscaleUp, tmp));
    }

    return updatedP;
}

vector<QPointF> Transform::scaleDown(const vector<QPointF> &points)
{
    vector<QPointF> updatedP;

    for(QPointF tmp: points) {
        updatedP.push_back(multiply(dscaleDown, tmp));
    }

    return updatedP;
}

vector<QPointF> Transform::clock(const vector<QPointF> &points)
{
    vector<QPointF> updatedP;

    for(QPointF tmp: points) {
        updatedP.push_back(multiply(dthetaClock, tmp));
    }

    return updatedP;
}

vector<QPointF> Transform::anti(const vector<QPointF> &points)
{
    vector<QPointF> updatedP;

    for(QPointF tmp: points) {
        updatedP.push_back(multiply(dthetaAnti, tmp));
    }

    return updatedP;
}

vector<QPointF> Transform::reflectX(const vector<QPointF> &points)
{
    vector<QPointF> updatedP;

    for(QPointF tmp: points) {
        updatedP.push_back(multiply(xReflect, tmp));
    }

    return updatedP;
}

vector<QPointF> Transform::shearX(const vector<QPointF> &points)
{
    vector<QPointF> updatedP;

    for(QPointF tmp: points) {
        updatedP.push_back(multiply(xShear, tmp));
    }

    return updatedP;
}

vector<QPointF> Transform::reflectY(const vector<QPointF> &points)
{
    vector<QPointF> updatedP;

    for(QPointF tmp: points) {
        updatedP.push_back(multiply(yReflect, tmp));
    }

    return updatedP;
}

vector<QPointF> Transform::shearY(const vector<QPointF> &points)
{
    vector<QPointF> updatedP;

    for(QPointF tmp: points) {
        updatedP.push_back(multiply(yShear, tmp));
    }

    return updatedP;
}

vector<QPointF> Transform::compose(const vector<QPointF> &points, vector<Transform::Op> ops)
{
    float arr[3][3]{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    for(Op tmp: ops) {
        switch (tmp) {
            case MOVEUP: mMultiply(arr, dxUp); break;
            case MOVEDOWN: mMultiply(arr, dxDown); break;
            case MOVELEFT: mMultiply(arr, dxLeft); break;
            case MOVERIGHT: mMultiply(arr, dxRight); break;
            case SCALEUP: mMultiply(arr, dscaleUp); break;
            case SCALEDOWN: mMultiply(arr, dscaleDown); break;
            case RANTI: mMultiply(arr, dthetaAnti); break;
            case RCLOCK: mMultiply(arr, dthetaClock); break;
            case REFLECTX: mMultiply(arr, xReflect); break;
            case REFLECTY: mMultiply(arr, yReflect); break;
            case SHEARX: mMultiply(arr, xShear); break;
            case SHEARY: mMultiply(arr, yShear); break;
        }
    }

    vector<QPointF> updatedP;

    for(QPointF tmp: points) {
        updatedP.push_back(multiply(arr, tmp));
    }

    return updatedP;
}

vector<QPointF> Transform::recentre(const vector<QPointF> &points, QPoint loc)
{
    float dx = -1*loc.x();
    float dy = -1*loc.y();

    float arr[3][3]{{1, 0, dx}, {0, 1, dy}, {0, 0, 1}};
    vector<QPointF> updatedP;

    for(QPointF tmp: points) {
        updatedP.push_back(multiply(arr, tmp));
    }

    return updatedP;
}

vector<QPointF> Transform::rotate(const vector<QPointF> &points, float angle)
{
    float arr[3][3]{{cos(angle), sin(angle), 0},
                    {-1*sin(angle), cos(angle), 0},
                    {0, 0, 1}};

    vector<QPointF> updatedP;

    for(QPointF tmp: points) {
        updatedP.push_back(multiply(arr, tmp));
    }

    return updatedP;
}



QPointF Transform::multiply(float arr[3][3], QPointF point)
{
    QPointF tmp;
    tmp.setX(arr[0][0]*point.x() + arr[0][1]*point.y() + arr[0][2]);
    tmp.setY(arr[1][0]*point.x() + arr[1][1]*point.y() + arr[1][2]);
    return tmp;
}

void Transform::mMultiply(float arr1[3][3], float arr2[3][3])
{
    float arr[3][3]{{0}, {0}, {0}};

    for(int r = 0; r < 3; r++) {
        for(int c = 0; c < 3; c++) {
            arr[r][c] = 0;
            for(int i = 0; i < 3; i++) {
                arr[r][c] += arr1[r][i]*arr2[i][c];
            }
        }
    }

    for(int r = 0; r < 3; r++) {
        for(int c = 0; c < 3; c++) {
            arr1[r][c] = arr[r][c];
        }
    }

}
