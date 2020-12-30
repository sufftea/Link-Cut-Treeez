#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <QGraphicsScene>
#include <QVector2D>

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

    int delta_w = 0;  // this.weight - parent.weight; for the root value is its weight
    int subtree_min;  // the smallest value of the subtree
    int subtree_max;  // the biggest value of the subtree

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


    Node(int weight = 0);
    Node(Node * parent, int weight = 0);
    ~Node();

    /* ========= INTSTANT OPERATIONS START ========= */

    int get_value();

    bool try_zig_left();
    bool try_zig_right();

    bool try_zig_zig_left();
    bool try_zig_zig_right();

    bool try_zig_zag_left();
    bool try_zig_zag_right();

    void splay();


    // [n] -- number of nodes in the path

    Node * get_solid_root();        // O(logn)
    Node * get_abstract_parent();   // O(logn)
    Node * get_path_parent();       // O(logn)

    bool is_solid_root();           // O(n)
    bool is_abstract_root();        // O(logn)
    bool is_left_child();           // O(n)
    bool is_right_child();          // O(n)
    bool is_solid_child();          // O(n)
    bool is_prefered_child();       // O(logn)
};


#endif // SPLAYTREE_H
