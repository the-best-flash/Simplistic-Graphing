#include "idmanager.h"

IdManager::IdManager(map<int, Connector*>* _connectors) :
        connectors(_connectors), curId(0)
{
}

void IdManager::AssignID(Connector* c)
{
    while(IsUsed(curID))
    {
        curID++;
    }

    UseID(curID, c);

    c->SetId(curID);
}

int IdManager::CurID()
{
    return curID;
}

void IdManager::SetID(int id)
{
    curID = id;
}

void IdManager::FreeID(int id)
{
    Connector* c = (*connectors)[id];

    c->Right()->Disconnect(c);
    c->Left()->Disconnect(c);

    delete c;

    connectors->erase(id);
}

void IdManager::UseID(int id, Connector* c)
{
    connectors->insert(pair<int, Connector*>(id, c));
}

bool IdManager::IsUsed(int id)
{
    return (connectors->find(id) != connectors->end());
}

void IdManager::CompactIDs()
{
    map<int, Connector*> temp(*connectors);

    connectors->clear();

    int count = 0;

    for(map<int, Connector*>::iterator it = temp.begin(); it != temp.end(); it++)
    {
        connectors->insert(pair<int, Connector*>(count, (*it).second));

        (*it).second->ChangeId(count);
        count++;
    }

    curID = count;
}
