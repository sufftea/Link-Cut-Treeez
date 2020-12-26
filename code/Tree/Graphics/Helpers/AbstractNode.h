#ifndef ABSTRACTNODE_H
#define ABSTRACTNODE_H

#include <QVector>
#include "Tree/Graphics/GraphicsAbstractNodeItem.h"

class Node;

class AbstractNode
{
public:
    AbstractNode * parent;
    QVector<AbstractNode * > children;
    Node * my_node;
    GraphicsAbstractNodeItem * graphics = nullptr;

    AbstractNode(Node * my_node);
    ~AbstractNode();


    bool is_prefered_child();

    int traverse_and_draw(int offset, int depth);
    void reset();
};

#endif // ABSTRACTNODE_H
