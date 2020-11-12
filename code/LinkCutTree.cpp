#include "LinkCutTree.h"


LinkCutTree::LinkCutTree(int size)
{
    nodes.reserve(size);
    for (int i = 0; i < size; i++) {
        nodes.push_back(new Node(i));
    }
}

void LinkCutTree::link(Node * s_tree, Node * to)
{
    if (s_tree->is_solid_root()) {
        s_tree->parent = to;
    } else {
        Node * root = s_tree->get_solid_root();
        root->parent = to;

        qDebug() << "Node passed to link() is not a root. The actual root has been linked";
    }
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
    this->v = v;
}

bool LinkCutTree::OperationExpose::make_step()
{
    if (current_step == Step::start_splaying_v) {
        v->start_splay();
        current_step = Step::splaying_v;

        Sequence::add("splay("
                      + QString::number(v->graphics->displayed_value)
                      + ")");
        Sequence::step_in();
    }

    else if (current_step == Step::splaying_v) {
        if (!v->make_step()) {
            pp = v->get_path_parent();
            current_step = Step::start_splaying_pp;

            Sequence::step_out();
        }
    }

    else if (current_step == Step::start_splaying_pp) {
        if (pp != nullptr) {
            pp->start_splay();
            current_step = Step::splaying_pp;

            Sequence::add("splay("
                          + QString::number(pp->graphics->displayed_value)
                          + ")");
            Sequence::step_in();
        } else {
            return 0;
        }
    }

    else if (current_step == Step::splaying_pp) {
        if (!pp->make_step()) {
            current_step = Step::cut_and_link;

            Sequence::step_out();
        }
    }

    else if (current_step == Step::cut_and_link) {
        pp->right = v;

        pp->width += v->width;
        if (pp->left != nullptr) {
            pp->width += pp->left->width;
        }

        current_step = start_splaying_v;

        Sequence::add("link right");
    }

    return 1;
}


// ================ STEP BY STEP LINK ==================

LinkCutTree::OperationLink::OperationLink(Node *v, Node *to)
{
    this->v = v;
    this->to = to;
}

LinkCutTree::OperationLink::~OperationLink()
{
    delete this->expose_operation;
}

bool LinkCutTree::OperationLink::make_step()
{
    if (current_step == Step::start_expose_v) {
        expose_operation = new OperationExpose(v);
        current_step = Step::expose_v;

        Sequence::add("expose("
                      + QString::number(v->graphics->displayed_value)
                      + ")");
        Sequence::step_in();
    }

    else if (current_step == Step::expose_v) {
        if (!expose_operation->make_step()) {
            current_step = Step::start_expose_to;

            Sequence::step_out();
        }
    }

    else if (current_step == Step::start_expose_to) {
        delete expose_operation;
        expose_operation = new OperationExpose(to);
        current_step = Step::expose_u;

        Sequence::add("expose("
                      + QString::number(to->graphics->displayed_value)
                      + ")");
        Sequence::step_in();
    }

    else if (current_step == Step::expose_u) {
        if (!expose_operation->make_step()) {
            current_step = Step::link;

            Sequence::step_out();
        }
    }

    else if (current_step == Step::link) {
        this->v->finish_operation();
        this->to->finish_operation();

//        to->parent = v;
        v->parent = to;

        Sequence::add("link parent");

        return 0;
    }

    return 1;
}
