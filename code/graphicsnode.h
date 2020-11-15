#ifndef GRAPHICSNODE_H
#define GRAPHICSNODE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include "animation.h"

class Node;


class GraphicsSolidNodeItem : public QGraphicsItem
{
private:
    QPointF last_pos = QPointF(0, 0);
    QPointF next_pos = QPointF(0, 0);

    Animation movement_anim;
    Animation selection_anim;

public:
    static const int node_width_px = 50;

    // 1 ~ element_width_px
    int relative_to_solid_parent_pos = 0;
    int displayed_value = 0;

    Node * my_node = nullptr;


    GraphicsSolidNodeItem(Node * my_node = nullptr, int displayed_value = 0);
    GraphicsSolidNodeItem(int relative_to_solid_parent_pos, Node * my_node = nullptr, int displayed_value = 0);

    /*
     * Draws the node on the given QGraphicsScene [scene]
    */
    void update_position(int node_offset, int solid_depth);
    void animate();
    void set_movement_easing_curve(std::function<double(double)> f);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // GRAPHICSNODE_H
