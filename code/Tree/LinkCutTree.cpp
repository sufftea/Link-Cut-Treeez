#include "Tree/LinkCutTree.h"


LinkCutTree::LinkCutTree()
{

}

LinkCutTree::~LinkCutTree()
{
    for (Node * node : nodes) {
        delete node;
    }

    delete current_operation;
}

void LinkCutTree::link(Node * v, Node * to)
{
    if (v->is_solid_root()) {
        v->parent = to;
    } else {
        // TODO: must splay the node instead;
        Node * root = v->get_solid_root();
        root->parent = to;
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

void LinkCutTree::init(int size)
{
    finish_operation();

    if (nodes.size() > 0) {
        for (Node * node : nodes) {
            delete node;
        }
        nodes.clear();
    }

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
    Sequence::add("Expose("
                  + QString::number(v->displayed_value)
                  + "):");
    Sequence::step_in();
    this->v = v;
}

LinkCutTree::OperationExpose::~OperationExpose()
{
    Sequence::add("expose finished!");
    Sequence::step_out();
}

bool LinkCutTree::OperationExpose::make_step()
{
    if (current_step == Step::start_splaying_v) {
        v->start_splay();
        current_step = Step::splaying_v;
    }

    else if (current_step == Step::splaying_v) {
        if (!v->make_step()) {
            pp = v->get_path_parent();
            current_step = Step::start_splaying_pp;
        }
    }

    else if (current_step == Step::start_splaying_pp) {
        if (pp != nullptr) {
            pp->start_splay();
            current_step = Step::splaying_pp;
        } else {
            return 0;
        }
    }

    else if (current_step == Step::splaying_pp) {
        if (!pp->make_step()) {
            current_step = Step::cut_and_link;
        }
    }

    else if (current_step == Step::cut_and_link) {
        pp->right = v;

        current_step = start_splaying_v;

        Sequence::add("connect v to it's path parent;");
    }

    return 1;
}


// ================ STEP BY STEP LINK ==================

LinkCutTree::OperationLink::OperationLink(Node *v, Node *to)
{
    Sequence::add("Link "
                  + QString::number(v->displayed_value)
                  + " to "
                  + QString::number(to->displayed_value)
                  + ":");
    Sequence::step_in();

    this->v = v;
    this->to = to;
}

LinkCutTree::OperationLink::~OperationLink()
{
    Sequence::add("link finished!");
    Sequence::step_out();
    delete this->expose_operation;
}

bool LinkCutTree::OperationLink::make_step()
{
    if (current_step == Step::start_expose_v) {
        expose_operation = new OperationExpose(v);
        current_step = Step::expose_v;
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

        Sequence::add("link "
                      + QString::number(v->displayed_value)
                      + " to "
                      + QString::number(to->displayed_value));

        return 0;
    }

    return 1;
}
