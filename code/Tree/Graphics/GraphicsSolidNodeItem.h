#ifndef GRAPHICSNODE_H
#define GRAPHICSNODE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsLineItem>
#include <QHash>

#include "Tree/Graphics/Helpers/animation.h"
#include "Tree/Graphics/Helpers/PathCreator.h"
#include "Tree/Graphics/Helpers/PathSmoother.h"
#include "Tree/Graphics/GraphicsNodeItem.h"

class Node;
class GraphicsLinkCutTree;


class GraphicsSolidNodeItem : public GraphicsNodeItem
{

public:
    enum class NodeLooks
    {
        normal = 0,
        user_selected
    };

    enum class NodeData
    {
        value = 0,
        sum,
        min,
        max
    };

    static const int node_size_px = 70;
    static const int node_bound_size_px = 100;

    Node * my_node = nullptr;


    GraphicsSolidNodeItem(Node * my_node, GraphicsLinkCutTree *graphcis_tree, QGraphicsScene * my_scene = nullptr);
    ~GraphicsSolidNodeItem() override;




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
    void update_position(int node_offset, int solid_depth);

    // updates node's pixmap after a display parameter
    void update_pixmap();

    /*
     * To draw path-parent connections with other nodes, the node needs to know the
     * positions of all the other nodes on the scene (so it can draw a line that doesn't
     * intersect other nodes)
    */
    void set_my_scene(QGraphicsScene * scene);


    void set_node_view(NodeLooks type);
    NodeLooks get_node_view();


    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    NodeLooks node_view = NodeLooks::normal;
    QGraphicsScene * my_scene = nullptr;
    QPixmap pix;
};

#endif // GRAPHICSNODE_H
