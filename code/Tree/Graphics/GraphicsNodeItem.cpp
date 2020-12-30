#include "GraphicsNodeItem.h"

GraphicsNodeItem::GraphicsNodeItem()
    : pix(QSize(node_size_px, node_size_px))
{

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

void GraphicsNodeItem::set_selection_type(GraphicsNodeItem::SelectionType type)
{
    if (this->selection != type) {
        this->selection = type;
        update_pixmap();
    }
}

GraphicsNodeItem::SelectionType GraphicsNodeItem::get_selection_type()
{
    return this->selection;
}
