#include "Node.h"

Node::Node(int displayed_value)
{
    this->graphics = new GraphicsNodeItem(this, displayed_value);

    calculate_depth();
}

Node::Node(Node * parent, int displayed_value)
{
    this->graphics = new GraphicsNodeItem(this, displayed_value);
    calculate_depth();

    this->parent = parent;
}

void Node::start_splay()
{
    finish_operation();
    current_operation = new OperationSplay(this);
}

bool Node::make_step()
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

void Node::finish_operation()
{
    if (current_operation != nullptr) {
        while (current_operation->make_step()) {}
        delete current_operation;
        current_operation = nullptr;
    }
}

Node *Node::get_solid_root()
{
    Node * current = this;
    while (!current->is_solid_root()) {
        current = current->parent;
    }
    return current;
}

Node *Node::get_abstart_root()
{
    return this; // do the actual implementation later
}

Node *Node::get_path_parent()
{
    Node * solid_root = this;
    while (!solid_root->is_solid_root()) {
        solid_root = solid_root->parent;
    }
    return solid_root->parent;
}

bool Node::is_solid_root()
{
    return this->parent == nullptr
            || (this->parent->left != this
            && this->parent->right != this);
}

bool Node::is_abstract_root()
{
    return parent == nullptr;
}

bool Node::is_left_child()
{
    if (parent != nullptr) {
        return parent->left == this;
    }
    return false;
}

bool Node::is_right_child()
{
    if (parent != nullptr) {
        return parent->right == this;
    }
    return false;
}

int Node::set_subtrees_width()
{
    this->width = 1;

    if (left != nullptr) {
        this->width += left->set_subtrees_width();
    }
    if (right != nullptr) {
        this->width += right->set_subtrees_width();
    }

    return this->width;
}

void Node::calculate_depth()
{
    // I have no idea how to implement this for now
    // maybe I'll use a descendant walkthrough for it.
}

int Node::alighn_graphics_nodes()
{
    int offset = 1;

    if (this->is_left_child()) {
        graphics->relative_to_parent_pos = -1;

        if (right != nullptr) {
            graphics->relative_to_parent_pos -= right->alighn_graphics_nodes();
        }
        if (left != nullptr) {
            offset += left->alighn_graphics_nodes();
        }
    } else if (this->is_right_child()) {
        graphics->relative_to_parent_pos = 1;

        if (right != nullptr) {
            graphics->relative_to_parent_pos += left->alighn_graphics_nodes();
        }
        if (left != nullptr) {
            offset += right->alighn_graphics_nodes();
        }
    } else if (this->is_solid_root()) {
        if (right != nullptr) {
            right->alighn_graphics_nodes();
        }
        if (left != nullptr) {
            left->alighn_graphics_nodes();
        }
    }

    return offset;
}

void Node::traverse_and_draw(QGraphicsScene *scene, int offset, int solid_depth)
{
    this->graphics->update_position(scene, offset, solid_depth);

    if (left != nullptr) {
        left->traverse_and_draw(scene, offset, solid_depth + 1);
    }
    if (right != nullptr) {
        right->traverse_and_draw(scene, offset, solid_depth + 1);
    }
}


/* ========= SPLAY OPERATION ========= */

void Node::OperationSplay::left_rotate()
{
    Node * p = v->parent;
    if (v->is_right_child()) {
        // widths
        p->width -= v->width;
        if (v->left != nullptr) {
            p->width += v->left->width;
        }

        v->width = p->width + 1;
        if (v->right != nullptr) {
            v->width += v->right->width;
        }


        // pointers
        p->right = v->left;
        v->left = p;
        v->parent = p->parent;
        p->parent = v;
    }
}

void Node::OperationSplay::right_rotate()
{
    Node * p = v->parent;
    if (v->is_left_child()) {
        // widths
        p->width -= v->width;
        if (v->right != nullptr) {
            p->width += v->right->width;
        }

        v->width = p->width + 1;
        if (p->left != nullptr) {
            v->width += p->left->width;
        }


        // pointers
        p->left = v->right;
        v->right = p;
        v->parent = p->parent;
        p->parent = v;
    }
}

Node::OperationSplay::OperationSplay(Node * v)
{
    this->v = v;
    this->path_parent = v->get_solid_root()->parent;
}

Node::OperationSplay::OperationSplay(Node * v, Node * tree_path_parent)
{
    this->v = v;
    path_parent = tree_path_parent;
}

Node::OperationSplay::~OperationSplay()
{

}

bool Node::OperationSplay::make_step()
{
    if (v->is_solid_root()) {
        v->parent = path_parent;

        Sequence::add("Done!");
        return 0;
    }

    Node * p = v->parent;


    if (p->is_solid_root()) {
        if (v->is_left_child()) {
            right_rotate();

            Sequence::add("Zig right");
        } else if (v->is_right_child()) {
            left_rotate();

            Sequence::add("Zig left");
        }
    } else if (v->is_left_child() && p->is_left_child()) {
        right_rotate();
        right_rotate();

        Sequence::add("Zig-Zig right");
    } else if (v->is_right_child() && p->is_right_child()) {
        left_rotate();
        left_rotate();

        Sequence::add("Zig-Zig left");
    } else if (v->is_right_child() && p->is_left_child()) {
        left_rotate();
        right_rotate();

        Sequence::add("Zig-Zag right");
    } else if (v->is_left_child() && p->is_right_child()) {
        right_rotate();
        left_rotate();

        Sequence::add("Zig-Zag left");
    }

    return 1;
}

