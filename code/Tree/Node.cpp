#include "Tree/Node.h"

Node::Node(int weight)
{   
    this->delta_w = weight;
}

Node::Node(Node * parent, int displayed_value)
    : Node(displayed_value)
{
    this->parent = parent;
}

Node::~Node()
{
    finish_operation(); // also deletes [current_operation]
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

int Node::get_value()
{    
    Node * it = this;
    int sum = 0;
    while (! it->is_solid_root()) {
        sum += it->delta_w;
        it = it->parent;
    }
    sum += it->delta_w;

    return sum;
}

bool Node::try_zig_left()
{
    Node * p = this->parent;
    if (this->is_right_child()) {
/*

        g                                   g
        *                                   *
        *                                   *
        p                                   v - this
       *  *              -->              *  *
      *     *                           *     *
     A        v - this                p        C
             * *                     * *
            *   *                   *   *
           B     C                 A     B

*/
        Node * B = this->left;
        Node * g = p->parent;

        // deltas
        int v_new_delta = this->delta_w + p->delta_w;
        int p_new_delta = p->delta_w - v_new_delta;
        int b_new_delta = 0;
        if (B != nullptr) {
            b_new_delta = B->delta_w + this->delta_w;
        }

        this->delta_w = v_new_delta;
        p->delta_w = p_new_delta;
        if (B != nullptr) {
            B->delta_w = b_new_delta;
        }


        // pointers
        p->right = B;
        if (B != nullptr) {
            B->parent = p;
        }

        this->left = p;
        p->parent = this;

        this->parent = g;
        if (g != nullptr) {
            if (g->left == p) {
                g->left = this;
            } else if (g->right == p) {
                g->right = this;
            }
        }

        return true;
    }

    return false;
}

bool Node::try_zig_right()
{
    Node * p = this->parent;
    if (this->is_left_child()) {
/*

              g                     g
              *                     *
              *                     *
              p                     v - this
            *  *                   *  *
          *     *         -->     *     *
 this - v        C               A        p
       * *                               * *
      *   *                             *   *
     A     B                           B     C

*/


        Node * B = this->right;
        Node * g = p->parent;

        // deltas
        int v_new_delta = this->delta_w + p->delta_w;
        int p_new_delta = p->delta_w - v_new_delta;
        int b_new_delta = 0;
        if (B != nullptr) {
            b_new_delta = B->delta_w + this->delta_w;
        }

        this->delta_w = v_new_delta;
        p->delta_w = p_new_delta;
        if (B != nullptr) {
            B->delta_w = b_new_delta;
        }



        // pointers
        p->left = B;
        if (B != nullptr) {
            B->parent = p;
        }

        this->right = p;
        p->parent = this;

        this->parent = g;
        if (g != nullptr) {
            if (g->left == p) {
                g->left = this;
            } else if (g->right == p) {
                g->right = this;
            }
        }

        return true;
    }

    return false;
}

bool Node::try_zig_zig_left()
{

/*

      gg                                     gg
      *                                      *
      *                                      *
      g                                      v - this
     *  *                                  *  *
    *     *                              *     *
   A        p                          p        D
           *  *         -->          *  *
          *     *                  *     *
         B        v - this       g        C
                 * *            * *
                *   *          *   *
               C     D        A     B


*/
    Node * p = this->parent; // can't be nullptr (after the if statement)
    if (this->is_right_child() && p->is_right_child()) {
        Node * g = p->parent; // can't be nullptr;
        Node * gg = g->parent; // CAN be nullptr

        Node * B = p->left;  // CAN be nullptr
        Node * C = this->left;  // CAN be nullptr

        // deltas
        int g_new_delta = - p->delta_w;
        int p_new_delta = - this->delta_w;
        int v_new_delta = this->delta_w + p->delta_w + g->delta_w;
        int b_new_delta = 0;
        if (B != nullptr) {
            b_new_delta = B->delta_w + p->delta_w;
        }
        int c_new_delta = 0;
        if (C != nullptr) {
            c_new_delta = C->delta_w + this->delta_w;
        }

        g->delta_w = g_new_delta;
        p->delta_w = p_new_delta;
        this->delta_w = v_new_delta;
        if (B != nullptr) {
            B->delta_w = b_new_delta;
        }
        if (C != nullptr) {
            C->delta_w = c_new_delta;
        }


        // pointers
        g->right = B;
        if (B != nullptr) {
            B->parent = g;
        }

        p->left = g;
        g->parent = p;

        p->right = C;
        if (C != nullptr) {
            C->parent = p;
        }

        this->left = p;
        p->parent = this;

        this->parent = gg;
        if (gg != nullptr) {
            if (gg->left == g) {
                gg->left = this;
            } else if (gg->right == g) {
                gg->right = this;
            }
        }

        return true;
    }

    return false;
}

bool Node::try_zig_zig_right()
{
/*
                 gg            gg
                 *             *
                 *             *
                 g             v
               *  *           *  *
             *     *         *     *
           p        D       A        p
         *  *          -->          *  *
       *     *                     *     *
     v        C                   B        g
    * *                                   * *
   *   *                                 *   *
  A     B                               C     D


*/
    Node * p = this->parent;
    if (this->is_left_child() && p->is_left_child()) {
        Node * g = p->parent;
        Node * gg = g->parent;
        Node * B = this->right;
        Node * C = p->right;

        // deltas
        int g_new_delta = - p->delta_w;
        int p_new_delta = - this->delta_w;
        int v_new_delta = this->delta_w + p->delta_w + g->delta_w;
        int b_new_delta = 0;
        if (B != nullptr) {
            b_new_delta = B->delta_w + this->delta_w;
        }
        int c_new_delta = 0;
        if (C != nullptr) {
            c_new_delta = C->delta_w + p->delta_w;
        }

        g->delta_w = g_new_delta;
        p->delta_w = p_new_delta;
        this->delta_w = v_new_delta;
        if (B != nullptr) {
            B->delta_w = b_new_delta;
        }
        if (C != nullptr) {
            C->delta_w = c_new_delta;
        }


        // pointers
        g->left = C;
        if (C != nullptr) {
            C->parent = g;
        }

        p->right = g;
        g->parent = p;
        p->left = B;
        if (B != nullptr) {
            B->parent = p;
        }

        this->right = p;
        p->parent = this;

        this->parent = gg;
        if (gg != nullptr) {
            if (gg->left == g) {
                gg->left = this;
            } else if (gg->right == g) {
                gg->right = this;
            }
        }

        return true;
    }

    return false;
}

bool Node::try_zig_zag_left()
{
/*

       gg                                gg
       *                                 *
       *                                 *
       g                                 v - this
      *    *                            *  *
     *         *                      *      *
    A              p      -->       g          p
                 *  *              * *        * *
               *     *            *   *      *   *
             v        D          A     B    C     D
            * *
           *   *
          B     C
*/

    Node * p = this->parent;
    if (this->is_left_child() && p->is_right_child()) {
        Node * g = p->parent;
        Node * gg = g->parent;
        Node * B = this->left;
        Node * C = this->right;

        // deltas
        int v_new_delta = this->delta_w + p->delta_w + g->delta_w;
        int p_new_delta = p->delta_w + g->delta_w - v_new_delta;
        int g_new_delta = g->delta_w - v_new_delta;

        if (B != nullptr) {
            int b_new_delta = B->delta_w + this->delta_w + p->delta_w;
            B->delta_w = b_new_delta;
        }
        if (C != nullptr) {
            int c_new_delta = C->delta_w + this->delta_w;
            C->delta_w  = c_new_delta;
        }
        this->delta_w = v_new_delta;
        p->delta_w = p_new_delta;
        g->delta_w = g_new_delta;


        // pointers
        g->right = B;
        if (B != nullptr) {
            B->parent = g;
        }

        p->left = C;
        if (C != nullptr) {
            C->parent = p;
        }

        this->left = g;
        g->parent = this;

        this->right = p;
        p->parent = this;

        this->parent = gg;
        if (gg != nullptr) {
            if (gg->left == g) {
                gg->left = this;
            } else if (gg->right == g) {
                gg->right = this;
            }
        }

        return true;
    }

    return false;
}

bool Node::try_zig_zag_right()
{
/*

                 gg                     gg
                 *                      *
                 *                      *
                 g                      v - this
              *   *                    *  *
          *        *                 *      *
      p             D    -->       p          g
     *  *                         * *        * *
    *     *                      *   *      *   *
   A        v - this            A     B    C     D
           * *
          *   *
         B     C

*/
    Node * p = this->parent;
    if (this->is_right_child() && p->is_left_child()) {
        Node * g = p->parent;
        Node * gg = g->parent;
        Node * B = this->left;
        Node * C = this->right;

        // deltas
        int v_new_delta = this->delta_w + p->delta_w + g->delta_w;
        int p_new_delta = p->delta_w + g->delta_w - v_new_delta;
        int g_new_delta = g->delta_w - v_new_delta;

        if (B != nullptr) {
            int b_new_delta = B->delta_w + this->delta_w;
            B->delta_w = b_new_delta;
        }
        if (C != nullptr) {
            int c_new_delta = C->delta_w + this->delta_w + p->delta_w;
            C->delta_w  = c_new_delta;
        }
        this->delta_w = v_new_delta;
        p->delta_w = p_new_delta;
        g->delta_w = g_new_delta;


        // pointers
        p->right = B;
        if (B != nullptr) {
            B->parent = p;
        }

        g->left = C;
        if (C != nullptr) {
            C->parent = g;
        }

        this->left = p;
        p->parent = this;

        this->right = g;
        g->parent = this;

        this->parent = gg;
        if (gg != nullptr) {
            if (gg->left == g) {
                gg->left = this;
            } else if (gg->right == g) {
                gg->right = this;
            }
        }

        return true;
    }

    return false;
}


void Node::splay()
{
    while (!this->is_solid_root()) {
        if (try_zig_zag_left()) continue;
        if (try_zig_zag_right()) continue;

        if (try_zig_zig_left()) continue;
        if (try_zig_zig_right()) continue;

        if (try_zig_left()) continue;
        if (try_zig_right()) continue;
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


/* ========= SPLAY OPERATION ========= */

Node::OperationSplay::OperationSplay(Node * v)
{
    SequanceLog::add("splay("
                  + QString::number(v->get_value())
                  + ")");
    SequanceLog::step_in();

    this->v = v;
}

Node::OperationSplay::~OperationSplay()
{
    SequanceLog::add("Splay finished!");
    SequanceLog::step_out();
}

bool Node::OperationSplay::make_step()
{
    if (v->is_solid_root()) {
        return 0;
    }

    if (v->try_zig_zag_left()) {
        SequanceLog::add("Zig-Zag left");
        return 1;
    }
    if (v->try_zig_zag_right()) {
        SequanceLog::add("Zig-Zag right");
        return 1;
    }
    if (v->try_zig_zig_left()) {
        SequanceLog::add("Zig-Zig left");
        return 1;
    }
    if (v->try_zig_zig_right()) {
        SequanceLog::add("Zig-Zig right");
        return 1;
    }

    if (v->try_zig_left()) {
        SequanceLog::add("Zig left");
        return 1;
    }
    if (v->try_zig_right()) {
        SequanceLog::add("Zig right");
        return 1;
    }

    return 1;
}

