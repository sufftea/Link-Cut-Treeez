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
        expose(v);
        expose(to);

        v->parent = to;
    }
}

void LinkCutTree::cut(Node *v)
{
    expose(v);
    v->left->delta_w += v->delta_w;
    if (v->left != nullptr) {
        v->left->parent = nullptr;
    }
    v->left = nullptr;
}

void LinkCutTree::expose(Node *v)
{
    while (true) {
        v->splay();
        if (v->parent == nullptr) {
            break;
        }
        v->parent->splay();

        v->delta_w -= v->parent->delta_w;
        v->parent->right->delta_w += v->parent->delta_w;
        v->parent->right = v;
    }
    v->right = nullptr;
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
    SequanceLog::add("Expose("
                  + QString::number(v->get_value())
                  + "):");
    SequanceLog::step_in();
    this->v = v;
}

LinkCutTree::OperationExpose::~OperationExpose()
{
    SequanceLog::add("expose finished!");
    SequanceLog::step_out();
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
            v->right = nullptr;
            SequanceLog::add("get rid of right subtree for " + QString::number(v->get_value()));
            return 0;
        }
    }

    else if (current_step == Step::splaying_pp) {
        if (!pp->make_step()) {
            current_step = Step::cut_and_link;
        }
    }

    else if (current_step == Step::cut_and_link) {
        v->delta_w -= pp->delta_w;
        if (pp->right != nullptr) {
            pp->right->delta_w += pp->delta_w;
        }
        pp->right = v;

        current_step = start_splaying_v;

        SequanceLog::add("connect v to its path parent;");
    }

    return 1;
}


// ================ STEP BY STEP LINK ==================

LinkCutTree::OperationLink::OperationLink(Node *v, Node *to)
{
    SequanceLog::add("Link "
                  + QString::number(v->get_value())
                  + " to "
                  + QString::number(to->get_value())
                  + ":");
    SequanceLog::step_in();

    this->v = v;
    this->to = to;
}

LinkCutTree::OperationLink::~OperationLink()
{
    SequanceLog::add("link finished!");
    SequanceLog::step_out();

    if (expose_operation != nullptr) {
        delete expose_operation;
    }
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

            delete expose_operation;
            expose_operation = nullptr;
        }
    }

    else if (current_step == Step::start_expose_to) {
        expose_operation = new OperationExpose(to);
        current_step = Step::expose_to;
    }

    else if (current_step == Step::expose_to) {
        if (!expose_operation->make_step()) {
            current_step = Step::link;

            delete expose_operation;
            expose_operation = nullptr;
        }
    }

    else if (current_step == Step::link) {
        v->finish_operation();
        to->finish_operation();

        v->parent = to;

        SequanceLog::add("linking "
                      + QString::number(v->get_value())
                      + " to "
                      + QString::number(to->get_value()));

        return 0;
    }

    return 1;
}

LinkCutTree::OperationCut::OperationCut(Node *v)
{
    this->v = v;
    SequanceLog::add("cut(" + QString::number(v->get_value()) + "):");
    SequanceLog::step_in();
}

LinkCutTree::OperationCut::~OperationCut()
{
    delete this->sbs_expose;
    this->sbs_expose = nullptr;

    SequanceLog::add("cut(" + QString::number(v->get_value()) + ") finished");
    SequanceLog::step_out();
}

bool LinkCutTree::OperationCut::make_step()
{
    if (current_step == Step::start_expose_v) {
       sbs_expose = new OperationExpose(v);
       current_step = Step::expose_v;
    } else if (current_step == Step::expose_v) {
       if (! sbs_expose->make_step()) {
           current_step = Step::cut;
       }
    } else if (current_step == Step::cut) {
        if (v->left != nullptr) {
            v->left->delta_w += v->delta_w;

            v->left->parent = nullptr;
            v->left = nullptr;

            SequanceLog::add("cut the left solid subtree");
        }
        return 0;
    }
    return 1;
}
