#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <QGraphicsScene>
#include <QVector2D>

#include "Helpers/StepByStepOperation.h"
#include "Tree/Graphics/GraphicsSolidNodeItem.h"
#include "Helpers/Sequance.h"


/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * BIG TO DO: possibly implement the descendant search support   *
 *                                                               *
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
     * Stores graphical representation of the node
    */
    GraphicsSolidNodeItem *graphics = nullptr;


    Node(int weight = 0);
    Node(Node * parent, int value = 0);
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

    Node * get_solid_root();
    Node * get_abstart_root();
    Node * get_path_parent();

    bool is_solid_root();
    bool is_abstract_root();
    bool is_left_child();
    bool is_right_child();
    bool is_child();
};


#endif // SPLAYTREE_H
