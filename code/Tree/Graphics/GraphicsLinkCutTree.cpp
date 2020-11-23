#include "Tree/Graphics/GraphicsLinkCutTree.h"
#include "Helpers/Colors.h"

GraphicsLinkCutTree::GraphicsLinkCutTree()
{
    scene = new QGraphicsScene;
//    scene->setBackgroundBrush(QBrush(MyColors::black));

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

        current_offset += root->graphics->traverse_and_update_position(current_offset);
        current_offset += 2;
    }

    this->scene->update();
}

void GraphicsLinkCutTree::init(int size)
{
    scene->clear();
    tree.init(size);
    for (Node * node : tree.nodes) {
        node->graphics = new GraphicsSolidNodeItem(node);

        scene->addItem(node->graphics);
        node->graphics->set_my_scene(this->scene);
    }
}

void GraphicsLinkCutTree::set_animation_easing_curve(std::function<double (double)> f)
{
    for (Node * node : tree.nodes) {
        node->graphics->set_movement_easing_curve(f);
    }
}

bool GraphicsLinkCutTree::set_animation_speed(qreal p)
{
    if (p <= 0 || p > 1) {
        return false;
    }
    qreal max_inc = 0.2;
    qreal inc = max_inc * p;

    for (Node * node : tree.nodes) {
        node->graphics->movement_anim.set_increment(inc);
    }

    return true;
}

void GraphicsLinkCutTree::animate_scene()
{
    for (Node * node : tree.nodes) {
        node->graphics->animate();
    }

    scene->update();
}
