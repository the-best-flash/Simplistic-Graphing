#include "connectionpoint.h"

ConnectionPoint::ConnectionPoint(GraphShape* p, int _dir, qreal xpos, qreal ypos) :
        QPointF(xpos, ypos), dir(_dir), parent(p)
{
}

ConnectionPoint::ConnectionPoint(GraphShape* p, int _dir, QPointF pt) :
        QPointF(pt), dir(_dir), parent(p)
{
}

ConnectionPoint::ConnectionPoint(GraphShape *p, ifstream &fin) :
        QPointF(), parent(p)
{
    this->Load(fin);
}

int ConnectionPoint::Dir()
{
    return dir;
}

void ConnectionPoint::Save(ofstream &fout)
{
    fout.write(&dir, sizeof(char));

    float _f = this->x();
    fout.write(&_f, sizeof(float));

    _f = this->y();
    fout.write(&_f, sizeof(float));
}

void ConnectionPoint::Load(ifstream &fin)
{
    fin.read(&dir, sizeof(char));

    float _f;

    fin.read(&_f, sizeof(float));
    this->setX(_f);

    fin.read(&_f, sizeof(float));
    this->setY(_f);
}
