#ifndef GRAPHICSABSTRACTNODEITEM_H
#define GRAPHICSABSTRACTNODEITEM_H

#include "Tree/Graphics/GraphicsNodeItem.h"

class AbstractNode;

class GraphicsAbstractNodeItem : public GraphicsNodeItem
{
public:
    AbstractNode * my_node;

    GraphicsAbstractNodeItem();

    void update_pixmap() override;
    void update_position(int node_offset, int solid_depth);
};

#endif // GRAPHICSABSTRACTNODEITEM_H
