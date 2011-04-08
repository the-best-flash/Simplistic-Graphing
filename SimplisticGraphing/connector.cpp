#include "connector.h"

Connector::Connector(QGraphicsScene* _scene, IdManager* _idMan, QObject *parent = 0) :
        QGraphicsItem(parent), GraphObject(scene), idMan(_idMan)
{
    id = idMan->GetID();
}

Connector::Connector(Connector& c) :
        QGraphicsItem(c), GraphObject(c.scene), idMan(c.idMan)
{
    id = idMan->GetID();
}

Connector::Connector(QGraphicsScene* scene, ifstream &fin, IdManager* _idMan, QObject *parent = 0) :
        QGraphicsItem(parent), GraphObject(scene, fin), idMan(_idMan)
{
    this->Load(fin);
}

void Connector::Save(ofstream &fout)
{
    GraphObject::Save(fout);

    fout.write(&id, sizeof(int));
}

void Connector::Load(ifstream &fin)
{
    GraphObject::Load(fin);

    fin.read(&id, sizeof(int));
}
