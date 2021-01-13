#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <QGraphicsScene>
#include <QVector2D>
#include <QStack>

#include "Helpers/StepByStepOperation.h"
#include "Tree/Graphics/GraphicsSolidNodeItem.h"
#include "Helpers/Sequence.h"
#include "Tree/Graphics/Helpers/AbstractNode.h"



/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * http://planarity.org/Klein_splay_trees_and_link-cut_trees.pdf *
 * Chapter 17.4                                                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/

class Node
{
private:


    StepByStepOperation * current_operation = nullptr;



public:
    /*
     * Parent points either to the parent of the node in a splay
     * tree, or, if the node is the root of a splay tree, poitns
     * to the prefered path's parent in the represented tree.
    */
    Node * parent = nullptr;
    Node * left = nullptr;
    Node * right = nullptr;

    int value;
    // aggregate functions
    int min_agg;
    int max_agg;
    int sum_agg;

    QStack<QString> current_operations;

    /*
     * Stores graphical representation of the node (in the concrete tree)
     *
     * A problem:
     * it's only needed for the GraphicsSolidNodeItem itself (to traverse
     * the tree while drawing it) and it may be deleted without the node
     * being aware of it.
    */
    GraphicsSolidNodeItem *concrete_tree_graphics = nullptr;

    /*
     * A corresponding abstract node. Needed to construct the abstract tree
     * for displaying it.
    */
    AbstractNode abstract;


    Node(int value = 0);
    Node(Node * parent, int value = 0);
    ~Node();

    /* ========= INTSTANT OPERATIONS START ========= */

    bool try_zig_left();
    bool try_zig_right();

    bool try_zig_zig_left();
    bool try_zig_zig_right();

    bool try_zig_zag_left();
    bool try_zig_zag_right();

    void splay();

    void update_aggregates(); // updates min/max/sum only for the node
//    void update_aggregates_up(); // updates aggregates from the node to the root

    // [n] -- number of nodes in the path

    Node * get_solid_root();        // O(log n)
    Node * get_abstract_parent();   // O(log n)
    Node * get_path_parent();       // O(log n)

    bool is_solid_root();           // O(1)
    bool is_abstract_root();        // O(log n)
    bool is_left_child();           // O(1)
    bool is_right_child();          // O(1)
    bool is_solid_child();          // O(1)
    bool is_prefered_child();       // O(log n)
};


#endif // SPLAYTREE_H
