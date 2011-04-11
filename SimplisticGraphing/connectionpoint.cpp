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

    int _i = connector.size();
    fout.write(&_i, sizeof(int));

    for(list<Connector*>::iterator it = connector.begin(); it != connector.end(); it++)
    {
        _i = (*it)->Id();
        fout.write(&_i, sizeof(int));
    }
}

void ConnectionPoint::Load(ifstream &fin)
{
    fin.read(&dir, sizeof(char));

    float _f;
    int _i;

    fin.read(&_f, sizeof(float));
    this->setX(_f);

    fin.read(&_f, sizeof(float));
    this->setY(_f);

    fin.read(&_i, sizeof(int));

    int size = _i;
    for(int i = 0; i < size; i++)
    {
        fin.read(&_i, sizeof(int));

        connector.push_back(man->GetConnector(_i));
    }
}

void ConnectionPoint::Disconnect(Connector* c)
{
    connector.remove(c);

    Connector* con = new Connector(c->scene(), man->GetIdManager(), NULL);

    con->setX(this->xp);
    con->setY(this->yp);

    if(c->Right() == this)
    {
        c->SetRight(con);
    }
    else if(c->Left() == this)
    {
        c->SetLeft(con);
    }
}

GraphShape* ConnectionPoint::Parent()
{
    return parent;
}
