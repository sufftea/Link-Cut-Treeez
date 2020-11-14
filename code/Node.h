#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <QGraphicsScene>
#include <QVector2D>

#include "StepByStepOperation.h"
#include "graphicsnode.h"
#include "sequence.h"


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
    /* Step by step implementation of the Splay(x)
     * Each step does either zig, zig-zig or zig-zag; */
    class OperationSplay : public StepByStepOperation
    {
    private:
        Node * v;
        Node * path_parent;

    public:
        /* [v] is the node that we want to move to the root
         *
         * [tree_path_parent] -- path parent of the tree that contains
         * the node [v], if not specified, will be found by calling
         * v->get_root() which will be slower. */
        OperationSplay(Node * v);
        OperationSplay(Node * v, Node * tree_path_parent);
        ~OperationSplay() override;

        bool make_step() override;
    };

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

    int width = 1;

    /*
     * Stores graphical representation of the node
    */
    GraphicsSolidNodeItem * graphics;


    /*
     * If you're looking for a value stored in the node, it's not
     * here. It's stored in the GraphicsNodeItem as displayed_value.
     *
     * That is because the value stored in the node has no effect
     * on anything, I'm going to use it only to make it possible to
     * differentiate displayed nodes.
    */



    Node(int displayed_value = 0);
    Node(Node * parent, int displayed_value = 0);


    /* ========= STEP BY STEP OPERATIONS START ========= */

    /*
     * The following functions are used to start a new operation.
     *
     * After an operation has been started, call make_step() to make
     * each next step of the operation or finish_operation() to finish
     * it immediately.
     *
     * If another operation has already been started, it will be
     * finished immediately using finish_operation() function; after
     * that, the new operation will be started;
    */
    void start_splay();
//    void start_split(Node * v);

    /*
     * after an operation has been started, call this function
     * to make each next step of the operation
    */
    bool make_step();

    /*
     * Call this function if there's no need to show the
     * operation step by step, the operation will be finished
     * immediatey
    */
    void finish_operation();


    /* ========= INTSTANT OPERATIONS START ========= */

//    void right_rotate();
//    void left_rotate();
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

    int set_subtrees_width();
    void calculate_depth();

    /*
     * Sets all the child nodes's relevant_to_parent_pos
     * in the tree by traversing them.
     *
     * Ignore the returned value, it is only needed for
     * the function itself.
    */
//    int align_graphics();


    /* ========== OPERATIONS FOR DRAWING THE TREE START =========== */

    /*
     * Traverses the tree and updates the position of each subnode on the scene
     *
     * Each node is placed in respect to its offset relative to the parent [offset],
     * and its depth [solid_depth]. For the first node solid depth must
     * be equal to zero.
     *
     * Offset is measured in node widths (offset = 3 is the same as 3 * node_width_px) and can be used
     * to move the tree horizontaly along the scene for displaying multiple trees.
     *
     * Should be called frome the root node in order to draw the entire solid tree.
    */
    void traverse_and_update_position(int & offset, int solid_depth = 0);
};


#endif // SPLAYTREE_H
