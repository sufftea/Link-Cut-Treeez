#include "GraphicsAbstractNodeItem.h"
#include "Tree/Graphics/Helpers/AbstractNode.h"

GraphicsAbstractNodeItem::GraphicsAbstractNodeItem()
{

}

void GraphicsAbstractNodeItem::update_pixmap()
{

}

void GraphicsAbstractNodeItem::update_position(int node_offset, int solid_depth)
{
    int pos_x = node_offset * GraphicsAbstractNodeItem::node_size_px * 0.6;
    int pos_y = solid_depth * GraphicsAbstractNodeItem::node_size_px;

    this->last_pos = this->pos();
    this->next_pos = QPointF(pos_x, pos_y);

    if (this->pos() != next_pos) {
        movement_anim.start();
    }
}
