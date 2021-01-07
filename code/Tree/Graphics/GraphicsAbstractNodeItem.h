#ifndef GRAPHICSABSTRACTNODEITEM_H
#define GRAPHICSABSTRACTNODEITEM_H

#include "Tree/Graphics/GraphicsNodeItem.h"
#include "Helpers/Colors.h"
#include <QPainter>

class AbstractNode;

class GraphicsAbstractNodeItem : public GraphicsNodeItem
{
public:
    enum class ViewType
    {
        normal = 0,
        user_selected,
    };


    static const int node_size_px = 60;
    AbstractNode * my_abstract_node = nullptr;


    GraphicsAbstractNodeItem(AbstractNode * my_abstract_node);

    void update_pixmap();
    void update_position(int node_offset, int solid_depth);

    void set_view_type(GraphicsAbstractNodeItem::ViewType type);
    ViewType get_view_type();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

private:
    ViewType view_type = ViewType::normal;
    QPixmap pix;
};

#endif // GRAPHICSABSTRACTNODEITEM_H
