#ifndef GRAPHICSNODE_H
#define GRAPHICSNODE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsLineItem>
#include <QHash>

#include "Tree/Graphics/Helpers/Animation.h"
#include "Tree/Graphics/Helpers/PathCreator.h"
#include "Tree/Graphics/Helpers/PathSmoother.h"

class Node;


class GraphicsSolidNodeItem : public QGraphicsItem
{
public:
    enum class SelectionType
    {
        no_selection = 0,
        user_selected,
        selection0,
        selection1,
    };

private:
    QPointF last_pos = QPointF(0, 0);
    QPointF next_pos = QPointF(0, 0);


    QGraphicsScene * my_scene = nullptr;
    QPixmap pix_node;

    SelectionType selection = SelectionType::no_selection;


public:
    static const int node_size_px = 60;
    static const int node_bound_size_px = 100;

    Animation movement_anim;
    Animation selection_anim;

    Node * my_node = nullptr;


    GraphicsSolidNodeItem(Node * my_node, QGraphicsScene * my_scene = nullptr);
    ~GraphicsSolidNodeItem() override;


    void update_position(int node_offset, int solid_depth);
    void animate();
    void set_movement_easing_curve(std::function<double(double)> f);
    void set_my_scene(QGraphicsScene * scene);
    void set_selection_type(SelectionType type);
    SelectionType get_selection_type();
    void update_pix();


    /*
     * Traverses the tree and updates the position for each node of the tree
     * Returns the width of the tree.
     *
     * Offset is measured in node widths (offset = 3 is the same as 3 * node_width_px) and can be used
     * to move the tree horizontaly along the scene for displaying multiple trees.
     *
     * Should be called frome the root node in order to draw the entire solid tree.
    */
    int traverse_and_update_position(int offset, int solid_depth = 0);


    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // GRAPHICSNODE_H
