#ifndef GRAPHICSABSTRACTNODEITEM_H
#define GRAPHICSABSTRACTNODEITEM_H

#include "Tree/Graphics/GraphicsNodeItem.h"
#include "Helpers/Colors.h"
#include <QPainter>

class AbstractNode;

class GraphicsAbstractNodeItem : public GraphicsNodeItem
{
public:
    AbstractNode * my_abstract_node = nullptr;

    GraphicsAbstractNodeItem(AbstractNode * my_abstract_node);

    void update_pixmap() override;
    void update_position(int node_offset, int solid_depth);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // GRAPHICSABSTRACTNODEITEM_H
