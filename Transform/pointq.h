#ifndef POINTQ_H
#define POINTQ_H

#include <QObject>
#include <queue>
#include <QPoint>

using namespace std;

class PointQ: public QObject
{
public:
    QPoint pop();
    bool empty();
    void reset();
    void push(QPoint point);
private:
    queue<QPoint> points;
};

#endif // POINTQ_H
