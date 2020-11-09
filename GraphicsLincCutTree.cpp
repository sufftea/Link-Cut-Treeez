#include "GraphicsLinkCutTree.h"

GraphicsLinkCutTree::GraphicsLinkCutTree(int size)
    : tree(size)
{
    scene = new QGraphicsScene;

    for (Node * node : tree.nodes) {
        scene->addItem(node->graphics);
    }
}

void GraphicsLinkCutTree::update_scene()
{
    for (Node * node: tree.nodes) {
        if (node->is_solid_root()) {
            node->alighn_graphics_nodes();
        }
    }

    int offset = 0;

    // draw one splay tree and move offset to give enough spase for the next tree
    for (Node * root: tree.nodes) {
        if (!root->is_solid_root()) {
            continue;
        }

        if (root->left != nullptr) {
            offset += root->left->width;
        }
        offset += 1;

        root->traverse_and_draw(this->scene, offset);

        if (root->right != nullptr) {
            offset += root->right->width;
        }
        offset += 1;
    }
}


