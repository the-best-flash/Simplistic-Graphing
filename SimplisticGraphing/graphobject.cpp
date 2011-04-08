#include "graphobject.h"

GraphObject::GraphObject(QGraphicsScene* scene) :
        scene(scene)

{
}

GraphObject::GraphObject(GraphObject &obj) :
        scene(obj.scene)
{

}
