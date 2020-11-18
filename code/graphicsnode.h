#ifndef GRAPHICSNODE_H
#define GRAPHICSNODE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsLineItem>

//#include "GraphicsLinkCutTree.h"
#include "animation.h"

class Node;


class GraphicsSolidNodeItem : public QGraphicsItem
{
private:
    QPointF last_pos = QPointF(0, 0);
    QPointF next_pos = QPointF(0, 0);

    Animation movement_anim;
    Animation selection_anim;

    Node * my_node = nullptr;
    GraphicsSolidNodeItem * graphics_tree;

public:
    static const int node_width_px = 50;


    GraphicsSolidNodeItem(Node * my_node);
    ~GraphicsSolidNodeItem() override;


    /*
     * Draws the node on the given QGraphicsScene [scene]
    */
    void update_position(int node_offset, int solid_depth);
    void animate();
    void set_movement_easing_curve(std::function<double(double)> f);
    QVector<QPoint> find_path(GraphicsSolidNodeItem * to, QGraphicsScene * scene);


    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // GRAPHICSNODE_H
