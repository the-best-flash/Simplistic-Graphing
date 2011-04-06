#ifndef GRAPHOBJECT_H
#define GRAPHOBJECT_H

#include "connector.h"

#include <fstream>
#include <vector>
using namespace std;

#include <QPointF>

class GraphObject
{
public:
    GraphObject();

    virtual void Save(ifstream &fin) = 0;
    virtual void Load(ofstream &fout) = 0;

protected:
    int id;
};

#endif // GRAPHOBJECT_H
