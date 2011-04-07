#ifndef GRAPHOBJECT_H
#define GRAPHOBJECT_H

#include "connector.h"

#include <fstream>
#include <vector>
using namespace std;

#include <QPointF>
#include <QGraphicsTextItem>

class GraphObject
{
public:
    enum Type{RECTANGLE, ELLIPSE, DIAMOND, TEXT, CONNECTOR, OTHER};

    GraphObject();
    GraphObject(ifstream &fin);
    GraphObject(GraphObject &obj);

    virtual void Save(ofstream &fout) = 0;
    virtual void Load(ifstream &fin) = 0;

protected:
    QGraphicsTextItem text;
};

#endif // GRAPHOBJECT_H
