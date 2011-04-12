#include "connectionmanager.h"

ConnectionManager::ConnectionManager(QGraphicsScene* _scene) :
        scene(_scene), idMan(&connection)
{
}

ConnectionManager::ConnectionManager(QGraphicsScene* _scene, ifstream &fin) :
        scene(_scene), idMan(&connection)
{
    this->Load(fin);
}

void ConnectionManager::Save(ofstream &fout)
{
    int _i;

    _i = idMan.CurID();
    fout.write(&_i, sizeof(int));

    _i = connection.size();
    fout.write(&_i, sizeof(int));

    for(map<int, Connector*>::iterator it = connection.begin(); it != connection.end(); it++)
    {
        (*it).second->Save(fout);
    }
}

void ConnectionManager::Load(ifstream &fin)
{
    int _i;

    fin.read(&_i, sizeof(int));
    idMan.SetID(_i);

    fin.read(&_i, sizeof(int));

    for(int i = 0; i < _i; i++)
    {
        new Connector(scene, fin, &idMan, scene);
    }
}

IdManager* ConnectionManager::GetIdManager()
{
    return this->idMan;
}

Connector* ConnectionManager::AddConnector()
{
    Connector* c = new Connector(scene, idMan, scene);

    this->idMan.AssignID(c);

    return c;
}

void ConnectionManager::DeleteConnector(int id)
{
    this->idMan.FreeID(id);
}

void ConnectionManager::DeleteConnector(Connector* c)
{
    this->idMan.FreeID(c->Id());
}

Connector* ConnectionManager::GetConnector(int id)
{
    return connection[id];
}
