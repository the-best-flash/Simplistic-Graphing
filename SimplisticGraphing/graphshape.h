#ifndef GRAPHSHAPE_H
#define GRAPHSHAPE_H

#include "graphobject.h"

class GraphShape : public GraphObject
{
public:
    GraphShape();

    void Save(ifstream &fin);
    void Load(ofstream &fout);

    virtual void Connect(Connector* c);

protected:
    vector<Connector*> connectors;
    vector<QPointF> connectionPts;
};

#endif // GRAPHSHAPE_H
