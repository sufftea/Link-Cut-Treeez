#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <QGraphicsScene>
#include <QVector2D>

#include "StepByStepOperation.h"
#include "Tree/Graphics/graphicsnode.h"
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

    public:
        /*
         * [v] is the node that we want to move to the root
         *
         * [tree_path_parent] -- path parent of the tree that contains
         * the node [v], if not specified, will be found by calling
         * v->get_root() which will be slower.
        */
        OperationSplay(Node * v);
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
    int displayed_value = 0;

    /*
     * Stores graphical representation of the node
    */
    GraphicsSolidNodeItem graphics;


    Node(int displayed_value = 0);
    Node(Node * parent, int displayed_value = 0);
    ~Node();


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

    void calculate_depth();


    /* ========== OPERATIONS FOR DRAWING THE TREE START =========== */

    /*
     * Traverses the tree and updates the position of each its child on the scene.
     * Returns the width of the tree.
     *
     * Offset is measured in node widths (offset = 3 is the same as 3 * node_width_px) and can be used
     * to move the tree horizontaly along the scene for displaying multiple trees.
     *
     * Should be called frome the root node in order to draw the entire solid tree.
    */
    int traverse_and_update_position(int offset, int solid_depth = 0);
};


#endif // SPLAYTREE_H
