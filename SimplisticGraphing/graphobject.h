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
    GraphObject(int id);
    GraphObject(GraphObject &obj);
    GraphObject(GraphObject &obj, int id);

    virtual void Save(ifstream &fin) = 0;
    virtual void Load(ofstream &fout) = 0;

protected:
    QGraphicsTextItem text;
};

#endif // GRAPHOBJECT_H
