#ifndef ABSTRACTNODE_H
#define ABSTRACTNODE_H

#include <QVector>
#include "Tree/Graphics/GraphicsAbstractNodeItem.h"

class Node;

class AbstractNode
{
public:
    AbstractNode * parent = nullptr;
    QVector<AbstractNode * > children;
    Node * my_solid_node;
    GraphicsAbstractNodeItem * graphics = nullptr;

    AbstractNode(Node * my_solid_node);
    ~AbstractNode();


    bool is_prefered_child();

    int traverse_and_draw(int offset, int depth = 0);

    // clears the children and parent
    void reset();
};

#endif // ABSTRACTNODE_H
