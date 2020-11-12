#include "Node.h"

Node::Node(int displayed_value)
{
    this->graphics = new GraphicsSolidNodeItem(this, displayed_value);

    calculate_depth();
}

Node::Node(Node * parent, int displayed_value)
{
    this->graphics = new GraphicsSolidNodeItem(this, displayed_value);
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

void Node::right_rotate()
{
    Node * p = this->parent;
    if (this->is_left_child()) {
        // widths
        p->width -= this->width;
        if (this->right != nullptr) {
            p->width += this->right->width;
        }

        this->width = p->width + 1;
        if (p->left != nullptr) {
            this->width += p->left->width;
        }


        // pointers
        p->left = this->right;

        if (this->right != nullptr) {
            this->right->parent = p;
        }

        this->right = p;
        this->parent = p->parent;
        p->parent = this;
    }
}

void Node::left_rotate()
{
    Node * p = this->parent;
    if (this->is_right_child()) {
        // widths
        p->width -= this->width;
        if (this->left != nullptr) {
            p->width += this->left->width;
        }

        this->width = p->width + 1;
        if (this->right != nullptr) {
            this->width += this->right->width;
        }


        // pointers
        p->right = this->left;

        if (this->left != nullptr) {
            this->left->parent = p;
        }

        this->left = p;
        this->parent = p->parent;
        p->parent = this;
    }
}

void Node::splay()
{
    while (!this->is_solid_root()) {
        if (this->is_left_child()) {
            right_rotate();
        } else if (this->is_right_child()) {
            left_rotate();
        }
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
    if (this->parent != nullptr) {
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

bool Node::is_child()
{
    return parent != nullptr
            && (parent->left == this
                || parent->right == this);
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

int Node::align_graphics()
{
    int offset = 1;

    if (this->is_left_child()) {
        graphics->relative_to_solid_parent_pos = -1;

        if (right != nullptr) {
            int child_offset = right->align_graphics();
            graphics->relative_to_solid_parent_pos -= child_offset;
            offset += child_offset;
        }
        if (left != nullptr) {
            offset += left->align_graphics();
        }
    } else if (this->is_right_child()) {
        graphics->relative_to_solid_parent_pos = 1;

        if (right != nullptr) {
            offset += right->align_graphics();
        }
        if (left != nullptr) {
            int child_offset = left->align_graphics();
            graphics->relative_to_solid_parent_pos += child_offset;
            offset -= child_offset;
        }
    } else if (this->is_solid_root()) {
        if (right != nullptr) {
            right->align_graphics();
        }
        this->graphics->relative_to_solid_parent_pos = 0;
        if (left != nullptr) {
            left->align_graphics();
        }
    }

    return offset;
}

void Node::traverse_and_update_position(int tree_offset, int solid_depth)
{
    this->graphics->update_position(tree_offset, solid_depth);

    if (left != nullptr) {
        left->traverse_and_update_position(tree_offset, solid_depth + 1);
    }
    if (right != nullptr) {
        right->traverse_and_update_position(tree_offset, solid_depth + 1);
    }
}


/* ========= SPLAY OPERATION ========= */

Node::OperationSplay::OperationSplay(Node * v)
{
    Sequence::add("splay("
                  + QString::number(v->graphics->displayed_value)
                  + ")");
    Sequence::step_in();

    this->v = v;
    this->path_parent = v->get_solid_root()->parent;
}

Node::OperationSplay::OperationSplay(Node * v, Node * tree_path_parent)
{
    Sequence::add("splay("
                  + QString::number(v->graphics->displayed_value)
                  + ")");
    Sequence::step_in();

    this->v = v;
    path_parent = tree_path_parent;
}

Node::OperationSplay::~OperationSplay()
{
    Sequence::add("Splay finished!");
    Sequence::step_out();
}

bool Node::OperationSplay::make_step()
{
    if (v->is_solid_root()) {
        return 0;
    }

    Node * p = v->parent;

    if (p->is_solid_root()) {
        if (v->is_left_child()) {
            v->right_rotate();

            Sequence::add("Zig right");
        } else if (v->is_right_child()) {
            v->left_rotate();

            Sequence::add("Zig left");
        }
    } else if (v->is_left_child() && p->is_left_child()) {
        v->right_rotate();
        v->right_rotate();

        Sequence::add("Zig-Zig right");
    } else if (v->is_right_child() && p->is_right_child()) {
        v->left_rotate();
        v->left_rotate();

        Sequence::add("Zig-Zig left");
    } else if (v->is_right_child() && p->is_left_child()) {
        v->left_rotate();
        v->right_rotate();

        Sequence::add("Zig-Zag right");
    } else if (v->is_left_child() && p->is_right_child()) {
        v->right_rotate();
        v->left_rotate();

        Sequence::add("Zig-Zag left");
    }

    return 1;
}

