#include "connectionmanager.h"

ConnectionManager::ConnectionManager(QGraphicsScene* _scene) :
        scene(_scene)
{
}

ConnectionManager::ConnectionManager(QGraphicsScene* _scene, ifstream &fin) :
        scene(_scene)
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

    for(vector<Connector*>::iterator it = connection.begin(); it != connection.end(); it++)
    {
        (*it)->Save(fout);
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
        connection.push_back(new Connector(scene, fin, &idMan, scene));
    }
}

Connector* ConnectionManager::AddConnector()
{

}

void ConnectionManager::DeleteConnector(int id)
{

}

Connector* ConnectionManager::GetConnector(int id)
{

}
