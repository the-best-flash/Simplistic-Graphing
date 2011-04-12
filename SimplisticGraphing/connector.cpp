#include "connector.h"

Connector::Connector(QGraphicsScene* _scene, IdManager* _idMan, QObject *parent = 0) :
        QGraphicsItem(parent), GraphObject(scene), idMan(_idMan), left(NULL), right(NULL)
{
    idMan->AssignID(this);
}

Connector::Connector(Connector& c) :
        QGraphicsItem(c), GraphObject(c.scene), idMan(c.idMan), left(NULL), right(NULL)
{
    idMan->AssignID(this);

    if(c.left != NULL && c.left->Parent() != NULL)
    {
        c.left->Parent()->Connect(this);
    }

    if(c.right != NULL && c.right->Parent() != NULL)
    {
        c.right->Parent()->Connect(this);
    }
}

Connector::~Connector()
{
    if(left != NULL && left->Parent() == NULL)
        delete left;

    if(right != NULL && right->Parent() == NULL)
        delete right;
}

Connector::Connector(QGraphicsScene* scene, ifstream &fin, IdManager* _idMan, QObject *parent = 0) :
        QGraphicsItem(parent), GraphObject(scene, fin), idMan(_idMan), left(NULL), right(NULL)
{
    this->Load(fin);
}

void Connector::Save(ofstream &fout)
{
    GraphObject::Save(fout);

    fout.write(&id, sizeof(int));
}

void Connector::Load(ifstream &fin)
{
    GraphObject::Load(fin);

    fin.read(&id, sizeof(int));

    idMan->UseID(id, this);
}

int Connector::Id()
{
    return id;
}

void Connector::SetLeft(ConnectionPoint* _left)
{
    if(this->left != NULL && this->left->Parent() == NULL)
        delete this->left;

    this->left = _left;
}

void Connector::SetRight(ConnectionPoint* _right)
{
    if(this->right != NULL && this->right->Parent() == NULL)
        delete this->left;

    this->right = _right;
}

ConnectionPoint* Connector::Left()
{
    return left;
}

ConnectionPoint* Connector::Right()
{
    return right;
}

void Connector::ChangeId(int _id)
{
    id = _id;
}

void Connector::SetId(int _id)
{
    id = _id;
}
