#ifndef GRAPHICSNODEITEM_H
#define GRAPHICSNODEITEM_H

#include <QGraphicsItem>

#include "Tree/Graphics/Helpers/Animation.h"

class GraphicsNodeItem : public QGraphicsItem
{
public:
    enum class SelectionType
    {
        no_selection = 0,
        user_selected,
        selection0,
        selection1,
    };

protected:
    QPointF last_pos = QPointF(0, 0);
    QPointF next_pos = QPointF(0, 0);

    QPixmap pix_node;

    SelectionType selection = SelectionType::no_selection;

public:
    static const int node_size_px = 60;

    Animation movement_anim;


    GraphicsNodeItem();
    ~GraphicsNodeItem() override;


    void animate();
    virtual void update_pixmap()=0;

    void set_my_scene(QGraphicsScene * scene);
    void set_selection_type(SelectionType type);

    SelectionType get_selection_type();
};

#endif // GRAPHICSNODEITEM_H
