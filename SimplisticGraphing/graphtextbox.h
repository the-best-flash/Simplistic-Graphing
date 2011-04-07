#ifndef GRAPHTEXTBOX_H
#define GRAPHTEXTBOX_H

#include <QGraphicsTextItem>
#include "graphshape.h"

class GraphTextbox : public QGraphicsTextItem, GraphShape
{
    Q_OBJECT
public:
    explicit GraphTextbox(QGraphicsScene* scene, QObject *parent = 0);

    void Save(ofstream &fout);
    void Load(ifstream &fin);

signals:

public slots:
};

#endif // GRAPHTEXTBOX_H
