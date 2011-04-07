#ifndef GRAPHELLIPSE_H
#define GRAPHELLIPSE_H

#include <QGraphicsEllipseItem>

#include "graphshape.h"

class GraphEllipse : public QGraphicsEllipseItem, GraphShape
{
    Q_OBJECT
public:
    explicit GraphEllipse(QObject *parent = 0);

    void Save(ifstream &fin);
    void Load(ofstream &fout);

signals:

public slots:

};

#endif // GRAPHELLIPSE_H
