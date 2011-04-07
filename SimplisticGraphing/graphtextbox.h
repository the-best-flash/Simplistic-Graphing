#ifndef GRAPHTEXTBOX_H
#define GRAPHTEXTBOX_H

#include <QGraphicsTextItem>
#include "graphshape.h"

class GraphTextbox : public QGraphicsTextItem, GraphShape
{
    Q_OBJECT
public:
    explicit GraphTextbox(QObject *parent = 0);

    void Save(ifstream &fin);
    void Load(ofstream &fout);

signals:

public slots:
};

#endif // GRAPHTEXTBOX_H
