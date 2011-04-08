#ifndef CONNECTIONPOINT_H
#define CONNECTIONPOINT_H

#include <QPointF>
#include <list>
#include "graphshape.h"
#include "connector.h"
#include "connectionmanager.h"

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

    void Disconnect(Connector* c);

private:
    char dir;
    list<Connector*> connector;
    GraphShape* parent;
    QPointF offset;
    bool standard;
    ConnectionManager* man;
};

#endif // CONNECTIONPOINT_H
