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
#include "Tree/Graphics/GraphicsNodeItem.h"

class Node;


class GraphicsSolidNodeItem : public GraphicsNodeItem
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

    QGraphicsScene * my_scene = nullptr;
    bool show_delta = false;

public:
    static const int node_size_px = 60;
    static const int node_bound_size_px = 100;

    Node * my_node = nullptr;


    GraphicsSolidNodeItem(Node * my_node, QGraphicsScene * my_scene = nullptr);
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
    void update_pixmap() override;

    void set_show_delta(bool show);
    void set_my_scene(QGraphicsScene * scene);


    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // GRAPHICSNODE_H
