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
    Connector(Connector& c);

signals:

public slots:

private:
    int id;
    IdManager* idMan;
};

#endif // CONNECTOR_H
