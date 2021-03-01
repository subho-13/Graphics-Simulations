#ifndef POINTQUEUE_H
#define POINTQUEUE_H

#include <QObject>
#include <queue>
#include <QPoint>

using namespace std;

class PointQueue : public QObject
{
    Q_OBJECT
public:
    explicit PointQueue(QObject *parent = nullptr);
    QPoint get();
    bool isEmpty();
public slots:
    void resetQueue();
    void add(QPoint loc);
private:
    queue<QPoint> locs;
};

#endif // POINTQUEUE_H
