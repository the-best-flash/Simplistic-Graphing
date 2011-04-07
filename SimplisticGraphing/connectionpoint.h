#ifndef CONNECTIONPOINT_H
#define CONNECTIONPOINT_H

#include <QPointF>

class ConnectionPoint : public QPointF
{
public:
    enum Direction{LEFT, RIGHT, UP, DOWN};

    explicit ConnectionPoint();

private:
    int dir;
};

#endif // CONNECTIONPOINT_H
