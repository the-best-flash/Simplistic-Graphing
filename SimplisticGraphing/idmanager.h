#ifndef IDMANAGER_H
#define IDMANAGER_H

#include <map>
using namespace std;

class IdManager
{
public:
    IdManager();

    int GetID();

    void FreeID(int id);
    void UseID(int id);
    void SetID(int id);

    map<int, int> CompactIDs();

private:
    map<int, bool> used;
    int curId;
};

#endif // IDMANAGER_H
