#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include <QGraphicsScene>

#include "connector.h"
#include "idmanager.h"

#include <fstream>
#include <vector>
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

    Connector* GetConnector(int id);

private:
    vector<Connector*> connection;
    IdManager idMan;
    QGraphicsScene* scene;
};

#endif // CONNECTIONMANAGER_H
