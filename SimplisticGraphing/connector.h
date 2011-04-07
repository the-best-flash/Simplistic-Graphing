#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QGraphicsItem>

#include "graphobject.h"
#include "idmanager.h"

class Connector : public QGraphicsItem, GraphObject
{
    Q_OBJECT
public:
    explicit Connector(IdManager* idMan, QObject *parent = 0);
    Connector(ifstream &fin, IdManager* idMan, QObject *parent = 0);
    Connector(Connector& c);

    void Save(ofstream &fout);
    void Load(ifstream &fin);

signals:

public slots:

private:
    int id;
    IdManager* idMan;
};

#endif // CONNECTOR_H
