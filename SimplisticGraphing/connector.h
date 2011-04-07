#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QGraphicsItem>
#include <QGraphicsScene>

#include "graphobject.h"
#include "idmanager.h"

class Connector : public QGraphicsItem, GraphObject
{
    Q_OBJECT
public:
    explicit Connector(QGraphicsScene* scene, IdManager* idMan, QObject *parent = 0);
    Connector(QGraphicsScene* scene, ifstream &fin, IdManager* idMan, QObject *parent = 0);
    Connector(Connector& c);

    void Save(ofstream &fout);
    void Load(ifstream &fin);

signals:

public slots:

protected:
    int id;
    IdManager* idMan;
};

#endif // CONNECTOR_H
