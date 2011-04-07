#include "connector.h"

Connector::Connector(IdManager* _idMan, QObject *parent = 0) :
        QGraphicsItem(parent), GraphObject(), idMan(_idMan)
{
    id = idMan->GetID();
}

Connector::Connector(Connector& c) :
        QGraphicsItem(c), GraphObject(), idMan(c.idMan)
{
    id = idMan->GetID();
}

Connector::Connector(ifstream &fin, IdManager* _idMan, QObject *parent = 0) :
        QGraphicsItem(parent), GraphObject(fin), idMan(_idMan)
{
    this->Load(fin);
}
