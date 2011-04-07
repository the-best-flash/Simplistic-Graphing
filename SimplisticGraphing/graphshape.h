#ifndef GRAPHSHAPE_H
#define GRAPHSHAPE_H

#include "graphobject.h"
#include "connectionpoint.h"

class GraphShape : public GraphObject
{
public:
    GraphShape();
    GraphShape(GraphShape &s);
    GraphShape(ifstream &fin);

    void Save(ofstream &fout);
    void Load(ifstream &fin);

    virtual void Connect(Connector* c);

protected:
    int type;
    vector<ConnectionPoint> connectionPts;
};

#endif // GRAPHSHAPE_H
