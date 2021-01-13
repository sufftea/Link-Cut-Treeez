#include "Tree/LinkCutTree.h"


LinkCutTree::LinkCutTree()
{

}

LinkCutTree::~LinkCutTree()
{
    finish_operation();

    for (Node * node : nodes) {
        delete node;
    }
}

void LinkCutTree::link(Node * v, Node * to)
{
    if (! v->is_abstract_root()) {
        qDebug() << "can't link";
        return;
    }

    expose(v);
    expose(to);

    v->left = to;
    v->parent = to->parent;
    to->parent = v;

    to->update_aggregates();
    v->update_aggregates();
}

void LinkCutTree::cut(Node *v)
{
    expose(v);
    if (v->left) {
        v->left->parent = nullptr;
    }
    v->left = nullptr;

    // after the expose(v), v is the only node that needs updating
    // since no other nodes are higher than it (in the solid tree)
    v->update_aggregates();
}

void LinkCutTree::expose(Node *v)
{
    while (true) {
        v->splay();

        if (!v->parent) {
            break;
        }

        v->parent->splay();
        v->parent->right = v;

        // v.parent (path-parent of v) is the root of its solid
        // tree so, again, the update is needed only for v.parent
        v->parent->update_aggregates();
    }

    v->right = nullptr;
    v->update_aggregates();
}

Node *LinkCutTree::get_abstract_root()
{
    if (nodes.size() > 0) {
        Node * n = nodes[0];
        while (!n->is_abstract_root()) {
            n = n->parent;
        }
        return n;
    } else {
        return nullptr;
    }
}

void LinkCutTree::init(int size)
{
    finish_operation();

    for (Node * node : nodes) {
        delete node;
    }
    nodes.clear();

    nodes.reserve(size);
    for (int i = 0; i < size; i++) {
        nodes.push_back(new Node(i));
    }
}

void LinkCutTree::start_expose(Node * v)
{
    finish_operation();
    current_operation = new OperationExpose(v);
}

void LinkCutTree::start_link(Node *v, Node *u)
{
    finish_operation();
    current_operation = new OperationLink(v, u);
}

void LinkCutTree::start_cut(Node *v)
{
    finish_operation();
    current_operation = new OperationCut(v);
}

bool LinkCutTree::make_step()
{
    if (current_operation != nullptr) {
        if (current_operation->make_step()) {
            return 1;
        } else {
            delete current_operation;
            current_operation = nullptr;
        }
    }
    return 0;
}

void LinkCutTree::finish_operation()
{
    if (current_operation != nullptr) {
        while (current_operation->make_step()) {}
        delete current_operation;
        current_operation = nullptr;
    }
}

// ================ STEP BY STEP EXPOSE ==================

LinkCutTree::OperationExpose::OperationExpose(Node *v)
{
    SequenceLog::add("Expose("
                  + QString::number(v->value)
                  + "):");
    SequenceLog::step_in();

    this->v = v;
    v->current_operations.push("expose");
}

LinkCutTree::OperationExpose::~OperationExpose()
{
    SequenceLog::add("expose finished!");
    SequenceLog::step_out();

    v->current_operations.pop();
}

bool LinkCutTree::OperationExpose::make_step()
{
    if (current_step == Step::start_splaying_v) {
        if (splayer) delete splayer;
        splayer = new OperationSplay(v);
        current_step = Step::splaying_v;
    }

    else if (current_step == Step::splaying_v) {
        if (! splayer->make_step()) {
            delete splayer;
            splayer = nullptr;
            current_step = Step::start_splaying_pp;
        }
    }

    else if (current_step == Step::start_splaying_pp) {
        if (!v->parent) {
            // v is the root of the abstract tree. finish the operation.
            SequenceLog::add("cut the rest of the path");
            v->right = nullptr;
            v->update_aggregates();
            current_step = Step::finished;
            return 0;
        }

        pp = v->parent;

        if (splayer) delete splayer;
        splayer = new OperationSplay(pp);
        current_step = Step::splaying_pp;
    }

    else if (current_step == Step::splaying_pp) {
        if (! splayer->make_step()) {
            delete splayer;
            splayer = nullptr;
            current_step = Step::link;
        }
    }

    else if (current_step == Step::link) {
        SequenceLog::add("connect to path parent");
        pp->right = v;
//        v->update_aggregates_up();
        pp->update_aggregates();
        current_step = Step::start_splaying_v;
    }

    else if (current_step == Step::finished) {
        return 0;
    }

    return 1;
}


// ================ STEP BY STEP LINK ==================

LinkCutTree::OperationLink::OperationLink(Node *v, Node *to)
{
    if (! v->is_abstract_root()) {
        SequenceLog::add("Cannot link. "
                         + QString::number(v->value)
                         + " must be the root of an abstract tree");
        current_step = Step::finished;

        return;
    }


    SequenceLog::add("Link "
                  + QString::number(v->value)
                  + " to "
                  + QString::number(to->value)
                  + ":");
    SequenceLog::step_in();

    this->v = v;
    this->to = to;

    current_step = Step::start_expose_v;

    v->current_operations.push("link");
    to->current_operations.push("link to");
}

LinkCutTree::OperationLink::~OperationLink()
{
    SequenceLog::add("link finished!");
    SequenceLog::step_out();

    if (expose_operation != nullptr) {
        delete expose_operation;
    }

    v->current_operations.pop();
    to->current_operations.pop();
}

bool LinkCutTree::OperationLink::make_step()
{
    if (current_step == Step::start_expose_v) {
        expose_operation = new OperationExpose(v);
        current_step = Step::expose_v;
    }

    else if (current_step == Step::expose_v) {
        if (! expose_operation->make_step()) {
            delete expose_operation;
            current_step = Step::start_expose_to;
        }
    }

    else if (current_step == Step::start_expose_to) {
        expose_operation = new OperationExpose(to);
        current_step = Step::expose_to;
    }

    else if (current_step == Step::expose_to) {
        if (! expose_operation->make_step()) {
            delete expose_operation;
            expose_operation = nullptr;
            current_step = Step::link;
        }
    }

    else if (current_step == Step::link) {
        SequenceLog::add("connect trees");

        v->left = to;
        v->parent = to->parent;
        to->parent = v;
//        to->update_aggregates_up();
        to->update_aggregates();
        v->update_aggregates();

        current_step = finished;

        return 0;
    }

    else if (current_step == Step::finished) {
        return 0;
    }


    return 1;
}


// ================ STEP BY STEP CUT ==================

LinkCutTree::OperationCut::OperationCut(Node *v)
{
    this->v = v;

    SequenceLog::add("cut(" + QString::number(v->value) + "):");
    SequenceLog::step_in();

    if (v->is_abstract_root()) {
        SequenceLog::add(QString::number(v->value) + " is already a root");
        current_step = Step::finished;
    }

    v->current_operations.push("cut");
}

LinkCutTree::OperationCut::~OperationCut()
{   
    if (this->expose_operation != nullptr) {
        delete this->expose_operation;
    }

    SequenceLog::add("cut(" + QString::number(v->value) + ") finished");
    SequenceLog::step_out();

    v->current_operations.pop();
}

bool LinkCutTree::OperationCut::make_step()
{
    if (current_step == Step::start_expose_v) {
        if (expose_operation) {
            delete expose_operation;
        }

        expose_operation = new OperationExpose(v);
        current_step = Step::expose_v;
    }

    else if (current_step == Step::expose_v) {
        if (! expose_operation->make_step()) {
            delete expose_operation;
            expose_operation = nullptr;
            current_step = Step::cut;
        }
    }

    else if (current_step == Step::cut) {
        if (v->left != nullptr) {
            SequenceLog::add("disconnect the left subtree");
            v->left->parent = nullptr;
            v->left = nullptr;
            v->update_aggregates();
        }

        current_step = Step::finished;
    }

    else if (current_step == Step::finished) {
        return 0;
    }

    return 1;
}



/* ========= STEP BY STEP SPLAY ========= */

LinkCutTree::OperationSplay::OperationSplay(Node * v)
{
    SequenceLog::add("splay("
                  + QString::number(v->value)
                  + ")");
    SequenceLog::step_in();

    this->v = v;
    v->current_operations.push("splay");
}

LinkCutTree::OperationSplay::~OperationSplay()
{
    SequenceLog::add("Splay finished!");
    SequenceLog::step_out();

    v->current_operations.pop();
}

bool LinkCutTree::OperationSplay::make_step()
{
    if (v->is_solid_root()) {
        return 0;
    }

    if (v->try_zig_zag_left()) {
        SequenceLog::add("Zig-Zag left");
        return 1;
    }
    if (v->try_zig_zag_right()) {
        SequenceLog::add("Zig-Zag right");
        return 1;
    }
    if (v->try_zig_zig_left()) {
        SequenceLog::add("Zig-Zig left");
        return 1;
    }
    if (v->try_zig_zig_right()) {
        SequenceLog::add("Zig-Zig right");
        return 1;
    }

    if (v->try_zig_left()) {
        SequenceLog::add("Zig left");
        return 1;
    }
    if (v->try_zig_right()) {
        SequenceLog::add("Zig right");
        return 1;
    }

    return 1;
}
