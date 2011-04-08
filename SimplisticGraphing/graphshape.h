#ifndef GRAPHSHAPE_H
#define GRAPHSHAPE_H

#include "graphobject.h"
#include "connectionpoint.h"

class GraphShape : public GraphObject
{
public:
    GraphShape(QGraphicsScene* scene);
    GraphShape(GraphShape &s);
    GraphShape(QGraphicsScene* scene, ifstream &fin);

    void Save(ofstream &fout);
    void Load(ifstream &fin);

    virtual void Connect(Connector* c);

protected:
    QGraphicsTextItem text;
    vector<ConnectionPoint> connectionPts;
};

#endif // GRAPHSHAPE_H
