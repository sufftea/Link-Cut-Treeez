#include "Tree/Node.h"


Node::Node(int value)
    : abstract(this)
{   
    this->value = value;
    this->sum_agg = value;
    this->min_agg = value;
    this->max_agg = value;
}

Node::Node(Node * parent, int weight)
    : Node(weight)
{
    this->parent = parent;
}

Node::~Node()
{

}

bool Node::try_zig_left()
{
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
    Node * p = this->parent;
    if (this->is_right_child()) {
        Node * A = p->left;
        Node * B = this->left;
        Node * C = this->right;
        Node * g = p->parent;




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

        // aggregates
        p->update_aggregates();
        this->update_aggregates();

        return true;
    }

    return false;
}

bool Node::try_zig_right()
{
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
    Node * p = this->parent;
    if (this->is_left_child()) {
        Node * A = this->left;
        Node * B = this->right;
        Node * C = p->right;
        Node * g = p->parent;


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

        // aggregates
        p->update_aggregates();
        this->update_aggregates();

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
    Node * p = this->parent;
    if (!this->is_right_child() || !p->is_right_child()) return false;

    p->try_zig_left();
    this->try_zig_left();
    return true;
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
    if (!this->is_left_child() || !p->is_left_child()) return false;

    p->try_zig_right();
    this->try_zig_right();
    return true;
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
    if (!this->is_left_child() || !p->is_right_child()) return false;

    this->try_zig_right();
    this->try_zig_left();
    return true;
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
    if (!this->is_right_child() || !p->is_left_child()) return false;

    this->try_zig_left();
    this->try_zig_right();
    return true;
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


void Node::update_aggregates()
{
    this->sum_agg = this->value
            + (this->right ? this->right->sum_agg : 0)
            + (this->left ? this->left->sum_agg : 0);

    this->min_agg = qMin((this->right ? this->right->min_agg : INT32_MAX),
                      (this->left ? this->left->min_agg : INT32_MAX));
    this->min_agg = qMin(this->min_agg, this->value);

    this->max_agg = qMax((this->right ? this->right->max_agg : INT32_MIN),
                      (this->left ? this->left->max_agg : INT32_MIN));
    this->max_agg = qMax(this->max_agg, this->value);
}

Node *Node::get_solid_root()
{
    Node * current = this;
    while (!current->is_solid_root()) {
        current = current->parent;
    }
    return current;
}

Node *Node::get_abstract_parent()
{
    if (this->left != nullptr) {
        // find the right-most node of the left child.
        Node * right_most = this->left;
        while (right_most->right != nullptr) {
            right_most = right_most->right;
        }
        return right_most;
    }

    Node * p = this;
    while (! p->is_solid_root()) {
        if (p->is_right_child()) {
            return p->parent;
        }
        p = p->parent;
    }

    return p->parent;
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
    return this->get_abstract_parent() == nullptr;
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

bool Node::is_solid_child()
{
    return ! this->is_solid_root();
}

bool Node::is_prefered_child()
{
    if (this->left != nullptr) {
        return true;
    }

    // if node is in right subtree
    Node * p = this;
    while (! p->is_solid_root()) {
        if (p->is_right_child()) {
            return true;
        }

        p = p->parent;
    }

    return false;
}



