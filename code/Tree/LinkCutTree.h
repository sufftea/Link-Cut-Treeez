#ifndef LINKCUTTREE_H
#define LINKCUTTREE_H

#include <QVector>
#include <QDebug>
#include "Node.h"
#include "Helpers/StepByStepOperation.h"
#include "Helpers/Sequence.h"

/*
abstract tree -- the big tree with selected paths that
is being represeted

solid tree -- a splay tree, represents one path from
the abstract tree.

concrete tree -- the forest of solid trees
*/

class LinkCutTree
{
private:

    /* Step by step implementation of Splay(x)
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

    class OperationExpose : public StepByStepOperation
    {
    private:
        enum Step {
            start_splaying_v = 0,
            splaying_v,
            start_splaying_pp,
            splaying_pp,
            link,
            finished
        };

        Node * v;
        Node * pp;
        Step current_step = start_splaying_v;

        OperationSplay *splayer = nullptr;

    public:
        OperationExpose(Node * v);
        ~OperationExpose() override;

        bool make_step() override;
    };

    class OperationLink : public StepByStepOperation
    {
    private:
        enum Step {
            start_expose_v = 0,
            expose_v,
            start_expose_to,
            expose_to,
            link,
            finished
        };

        Step current_step = Step::start_expose_v;
        OperationExpose * expose_operation = nullptr;

        Node * v;
        Node * to;

    public:
        OperationLink(Node * v, Node * to);
        ~OperationLink() override;

        bool make_step() override;
    };

    class OperationCut : public StepByStepOperation
    {
    private:
        enum Step {
            start_expose_v = 0,
            expose_v,
            cut,
            finished
        };

        Node * v;
        Step current_step = start_expose_v;
        OperationExpose * expose_operation = nullptr;

    public:
        OperationCut(Node * v);
        ~OperationCut() override;

        bool make_step() override;
    };

    StepByStepOperation * current_operation = nullptr;

public:
    QVector<Node*> nodes;


    LinkCutTree();
    ~LinkCutTree();



    /* ========= STEP BY STEP OPERATIONS START ========= */

    /*
     * The following functions are used to start a new operation.
     *
     * After an operation has been started, call make_step() to make
     * each next step of the operation or finish_operation() to finish
     * it immediately.
     *
     * If another operation has already been started, it'll be
     * finished immediately using finish_operation() function; after
     * that, the new operation will be started;
    */
    void start_expose(Node * v); // DONE
    void start_link(Node * v, Node * u); // DONE
    void start_cut(Node * v); // DONE

    /*
     * after an operation has been started, call this function
     * to make each next step of the operation.
    */
    bool make_step(); // DONE


    /*
     * Call this function if there's no need to show the
     * operation step by step. The operation will be finished
     * immediatey.
    */
    void finish_operation(); // DONE



    /* ========= INTSTANT OPERATIONS START ========= */

    void link(Node * v, Node * to);
    void cut(Node * v);
    void expose(Node * v);

    Node * get_abstract_root();
    void init(int size);
};


#endif // LINKCUTTREE_H
