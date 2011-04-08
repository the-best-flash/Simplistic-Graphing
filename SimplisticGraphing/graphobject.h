#ifndef GRAPHOBJECT_H
#define GRAPHOBJECT_H

#include "connector.h"

#include <fstream>
#include <vector>
using namespace std;

#include <QPointF>
#include <QGraphicsTextItem>
#include <QGraphicsScene>

class GraphObject
{
public:
    enum Type{RECTANGLE, ELLIPSE, DIAMOND, TEXT, CONNECTOR, OTHER};

    GraphObject(QGraphicsScene* scene);
    GraphObject(GraphObject &obj);

    virtual void Save(ofstream &fout) = 0;
    virtual void Load(ifstream &fin) = 0;

protected:
    int type;
    QGraphicsScene* scene;
};

#endif // GRAPHOBJECT_H
