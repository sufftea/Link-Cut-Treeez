#include "GraphicsLinkCutTree.h"

GraphicsLinkCutTree::GraphicsLinkCutTree()
{
    scene = new QGraphicsScene;

    animation_timer = new QTimer;
    animation_timer->setInterval(20);
    connect(animation_timer, SIGNAL(timeout()), this, SLOT(animate_scene()));
    animation_timer->start();
}

GraphicsLinkCutTree::~GraphicsLinkCutTree()
{
    animation_timer->stop();
    delete animation_timer;
    delete scene;
}

void GraphicsLinkCutTree::update_scene()
{
    int current_offset = 0;

    // draw one splay tree and move offset to give enough spase for the next tree
    for (Node * root: tree.nodes) {
        if (!root->is_solid_root()) {
            continue;
        }

        current_offset += root->traverse_and_update_position(current_offset);
        current_offset += 2;
    }

    this->scene->update();
}

void GraphicsLinkCutTree::init(int size)
{
    tree.init(size);
    for (Node * node : tree.nodes) {
        scene->addItem(&node->graphics);
        node->graphics.set_my_scene(this->scene);
    }
}

void GraphicsLinkCutTree::set_movement_easing_curve(std::function<double (double)> f)
{
    for (Node * node : tree.nodes) {
        node->graphics.set_movement_easing_curve(f);
    }
}

void GraphicsLinkCutTree::animate_scene()
{
    for (Node * node : tree.nodes) {
        node->graphics.animate();
    }

    scene->update();
}
