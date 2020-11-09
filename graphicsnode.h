#ifndef GRAPHICSNODE_H
#define GRAPHICSNODE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsLineItem>

class Node;


class GraphicsNodeItem : public QGraphicsItem
{
    QGraphicsLineItem * parent_line = nullptr;

public:
    static const int element_width_px = 50;

    // 1 ~ element_width_px
    int relative_to_parent_pos = 0;
    QPoint last_pos;

    int displayed_value = 0;

    Node * my_node = nullptr;


    GraphicsNodeItem(Node * my_node = nullptr, int displayed_value = 0);
    GraphicsNodeItem(int relative_to_parent_pos, Node * my_node = nullptr, int displayed_value = 0);

    /*
     * Draws the node on the given QGraphicsScene [scene]
    */
    void update_position(QGraphicsScene * scene, int offset, int solid_depth);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // GRAPHICSNODE_H
