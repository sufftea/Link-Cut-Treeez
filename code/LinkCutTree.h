#ifndef LINKCUTTREE_H
#define LINKCUTTREE_H

#include <QVector>
#include <QDebug>
#include "Node.h"
#include "StepByStepOperation.h"
#include "sequence.h"

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
    class OperationExpose : public StepByStepOperation
    {
    private:
        enum Step {
            start_splaying_v = 0,
            start_splaying_pp,
            splaying_v,
            splaying_pp,
            cut_and_link
        };

        Node * v;
        Node * pp;
        Step current_step = start_splaying_v;

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
            expose_u,
            link
        };

        Step current_step = Step::start_expose_v;
        OperationExpose * expose_operation;

        Node * v;
        Node * to;

    public:
        OperationLink(Node * v, Node * to);
        ~OperationLink() override;

        bool make_step() override;
    };


    StepByStepOperation * current_operation = nullptr;

public:
    QVector<Node*> nodes;


    LinkCutTree(int size); // DONE



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
    void start_expose(Node * v); // DONE (almost)
    void start_link(Node * v, Node * u); // DONE
    void start_cut(Node * v);

    void start_lca(Node * a, Node * b);
    void start_add(Node * v, int c);


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

    void link(Node * v, Node * to); // DONE
    Node * get_abstract_root(); // DONE
};


#endif // LINKCUTTREE_H
