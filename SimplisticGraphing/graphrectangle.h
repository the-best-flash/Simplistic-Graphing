#ifndef GRAPHRECTANGLE_H
#define GRAPHRECTANGLE_H

#include <QGraphicsRectItem>

#include "graphshape.h"

class GraphRectangle : public QGraphicsRectItem, GraphShape
{
    Q_OBJECT
public:
    explicit GraphRectangle(QGraphicsScene* scene, QObject *parent = 0);

    void Save(ofstream &fout);
    void Load(ifstream &fin);

signals:

public slots:
};

#endif // GRAPHRECTANGLE_H
