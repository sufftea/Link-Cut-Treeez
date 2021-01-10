#include "GraphicsNodeItem.h"

GraphicsNodeItem::GraphicsNodeItem(GraphicsLinkCutTree *graphics_tree)
{
    this->graphics_tree = graphics_tree;
}

GraphicsNodeItem::~GraphicsNodeItem()
{

}

void GraphicsNodeItem::animate()
{
    // animate the position
    if (movement_anim.get_is_active()) {
        qreal v = movement_anim.get_value();
        QPointF m = (next_pos - last_pos) * v;
        this->setPos(last_pos + m);
    }
}
