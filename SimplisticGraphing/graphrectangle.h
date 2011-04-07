#ifndef GRAPHRECTANGLE_H
#define GRAPHRECTANGLE_H

#include <QGraphicsRectItem>

#include "graphshape.h"

class GraphRectangle : public QGraphicsRectItem, GraphShape
{
    Q_OBJECT
public:
    explicit GraphRectangle(QObject *parent = 0);

    void Save(ifstream &fin);
    void Load(ofstream &fout);

signals:

public slots:
};

#endif // GRAPHRECTANGLE_H
