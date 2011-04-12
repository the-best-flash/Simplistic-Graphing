#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include <QGraphicsScene>

#include "connector.h"
#include "idmanager.h"

#include <fstream>
#include <map>
using namespace std;

class ConnectionManager
{
public:
    ConnectionManager(QGraphicsScene* scene);
    ConnectionManager(QGraphicsScene* scene, ifstream &fin);

    void Save(ofstream &fout);
    void Load(ifstream &fin);

    Connector* AddConnector();
    void DeleteConnector(int id);
    void DeleteConnector(Connector* c);

    Connector* GetConnector(int id);

    IdManager* GetIdManager();

private:
    map<int, Connector*> connection;
    IdManager idMan;
    QGraphicsScene* scene;
};

#endif // CONNECTIONMANAGER_H
