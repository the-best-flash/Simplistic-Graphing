#ifndef GRAPHSHAPE_H
#define GRAPHSHAPE_H

#include "graphobject.h"
#include "connectionpoint.h"

class GraphShape : public GraphObject
{
public:
    GraphShape();

    void Save(ifstream &fin);
    void Load(ofstream &fout);

    virtual void Connect(Connector* c);

protected:
    int type;
    vector<Connector*> connectors;
    vector<ConnectionPoint> connectionPts;
};

#endif // GRAPHSHAPE_H
