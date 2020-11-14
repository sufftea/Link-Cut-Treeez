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
    int current_offset = 0;

    // draw one splay tree and move offset to give enough spase for the next tree
    for (Node * root: tree.nodes) {
        if (!root->is_solid_root()) {
            continue;
        }

        root->traverse_and_update_position(current_offset);
        current_offset += 2;
    }

    this->scene->update();
}
