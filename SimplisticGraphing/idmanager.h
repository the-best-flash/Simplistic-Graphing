#ifndef IDMANAGER_H
#define IDMANAGER_H

#include "connector.h"

#include <map>
using namespace std;

class IdManager
{
public:
    IdManager(map<int, Connector*>* _connectors);

    void AssignID(Connector* c);
    int CurID();

    void FreeID(int id);
    void UseID(int id, Connector* c);
    void SetID(int id);

    map<int, int> CompactIDs();

private:
    bool IsUsed(int id);

    map<int, Connector*>* connectors;
    int curId;
};

#endif // IDMANAGER_H
