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
            node->align_graphics();
        }
    }

    int current_offset = 0;


    // draw one splay tree and move offset to give enough spase for the next tree
    for (Node * root: tree.nodes) {
        if (!root->is_solid_root()) {
            continue;
        }

        if (root->left != nullptr) {
            current_offset += root->left->width;
        }
        current_offset += 1;

        root->traverse_and_update_position(current_offset);

        if (root->right != nullptr) {
            current_offset += root->right->width;
        }
        current_offset += 1;
    }

    this->scene->update();
}


