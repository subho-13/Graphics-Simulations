#include "pointqueue.h"

PointQueue::PointQueue(QObject *parent) : QObject(parent)
{
}

QPoint PointQueue::get()
{
    QPoint tmp;
    tmp.setX(0);
    tmp.setY(0);
    if(!locs.empty()) {
        tmp = locs.front();
        locs.pop();
    }

    return tmp;
}

bool PointQueue::isEmpty()
{
    return locs.empty();
}

void PointQueue::resetQueue()
{
    queue<QPoint> empty;
    swap(locs, empty);
}

void PointQueue::add(QPoint loc)
{
    locs.push(loc);
}
