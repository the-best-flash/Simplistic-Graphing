#ifndef CONNECTIONPOINT_H
#define CONNECTIONPOINT_H

#include <QPointF>
#include <vector>
#include "graphshape.h"
#include "connector.h"

class ConnectionPoint : public QPointF
{
public:
    enum Direction{LEFT, RIGHT, UP, DOWN};

    ConnectionPoint(GraphShape* parent, int dir, qreal xpos, qreal ypos);
    ConnectionPoint(GraphShape* parent, int dir, QPointF pt);
    ConnectionPoint(GraphShape* parent, ifstream &fin);

    int Dir();

    void Save(ofstream &fout);
    void Load(ifstream &fin);

private:
    char dir;
    vector<Connector*> connector;
    GraphShape* parent;
};

#endif // CONNECTIONPOINT_H
