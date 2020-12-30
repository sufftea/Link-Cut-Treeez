#include "Tree/Graphics/GraphicsLinkCutTree.h"
#include "Helpers/Colors.h"

GraphicsLinkCutTree::GraphicsLinkCutTree()
{
    concrete_tree_scene = new QGraphicsScene;
    abstract_tree_scene = new QGraphicsScene;

    animation_timer = new QTimer;
    animation_timer->setInterval(20);
    connect(animation_timer, SIGNAL(timeout()), this, SLOT(animate_scene()));
    animation_timer->start();
}

GraphicsLinkCutTree::~GraphicsLinkCutTree()
{
    animation_timer->stop();
    delete animation_timer;

    delete concrete_tree_scene;
    delete abstract_tree_scene;
}

void GraphicsLinkCutTree::update_concrete_tree_scene()
{
    int current_offset = 0;

    // draw one splay tree and move offset to give enough spase for the next tree
    for (Node * node: tree.nodes) {
        node->concrete_tree_graphics->update_pixmap();

        if (!node->is_solid_root()) {
            continue;
        }

        current_offset += node->concrete_tree_graphics->traverse_and_update_position(current_offset);
        current_offset += 4;
    }

    this->concrete_tree_scene->update();
}

void GraphicsLinkCutTree::update_abstract_tree_scene()
{
    // create the abstract tree
    for (Node * node : tree.nodes) {
        node->abstract.reset();
        node->abstract.graphics->update_pixmap();
    }

    QVector<AbstractNode*> roots;

    for (Node * node : tree.nodes) {
        Node * parent = node->get_abstract_parent();
        if (parent == nullptr) {
            roots.push_back(& node->abstract);
            continue;
        }

        node->abstract.parent = & parent->abstract;
        parent->abstract.children.push_back(& node->abstract);
    }

    // traverse the tree and draw each graphicsNode
    int offset = 1;
    for (AbstractNode * root : roots) {
        offset += root->traverse_and_draw(offset);
        offset += 2;
    }

    this->abstract_tree_scene->update();
}

void GraphicsLinkCutTree::init(int size)
{
    concrete_tree_scene->clear();
    abstract_tree_scene->clear();

    tree.init(size);

    for (Node * node : tree.nodes) {
        // set concrete tree graphics
        node->concrete_tree_graphics = new GraphicsSolidNodeItem(node, this->show_delta, this->concrete_tree_scene);

        concrete_tree_scene->addItem(node->concrete_tree_graphics);
        node->concrete_tree_graphics->set_my_scene(this->concrete_tree_scene);

        // set abstract tree graphics
        node->abstract.graphics = new GraphicsAbstractNodeItem(&node->abstract);
        abstract_tree_scene->addItem(node->abstract.graphics);
    }
}

void GraphicsLinkCutTree::update_scene()
{
    if (active_scene_type == "concrete") {
        update_concrete_tree_scene();
    } else if (active_scene_type == "abstract") {
        update_abstract_tree_scene();
    }
}

void GraphicsLinkCutTree::set_animation_easing_curve(std::function<double (double)> f)
{
    for (Node * node : tree.nodes) {
        node->concrete_tree_graphics->movement_anim.set_easing_curve(f);
        node->abstract.graphics->movement_anim.set_easing_curve(f);
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
        node->concrete_tree_graphics->movement_anim.set_increment(inc);
        node->abstract.graphics->movement_anim.set_increment(inc);
    }

    return true;
}

Node *GraphicsLinkCutTree::node_at(QPoint pos)
{
    if (tree.nodes.size() == 0) {
        return nullptr;
    }

    // move pos by an offset
    pos.rx() -= GraphicsSolidNodeItem::node_size_px / 2;
    pos.ry() -= GraphicsSolidNodeItem::node_size_px / 2;

    if (active_scene_type == "concrete") {
        GraphicsSolidNodeItem * res = nullptr;
        qreal closest_dist = 99999999;
        for (auto node : tree.nodes) {
            qreal dist = QVector2D(node->concrete_tree_graphics->pos() - pos).length();
            if (dist < closest_dist) {
                closest_dist = dist;
                res = node->concrete_tree_graphics;
            }
        }

        if (closest_dist <= GraphicsSolidNodeItem::node_size_px) {
            return res->my_node;
        }
    } else if (active_scene_type == "abstract") {
        GraphicsAbstractNodeItem * res = nullptr;
        qreal closest_dist = 99999999;
        for (auto node : tree.nodes) {
            qreal dist = QVector2D(node->abstract.graphics->pos() - pos).length();
            if (dist < closest_dist) {
                closest_dist = dist;
                res = node->abstract.graphics;
            }
        }

        if (closest_dist <= GraphicsSolidNodeItem::node_size_px) {
            return res->my_abstract_node->my_solid_node;
        }
    }

    return nullptr;
}

void GraphicsLinkCutTree::unselect_all_nodes()
{
    for (Node * node : tree.nodes) {
        node->concrete_tree_graphics->set_selection_type(GraphicsNodeItem::SelectionType::no_selection);
        node->abstract.graphics->set_selection_type(GraphicsNodeItem::SelectionType::no_selection);
    }
}

void GraphicsLinkCutTree::set_show_delta(bool show_delta)
{
    this->show_delta = show_delta;
    for (Node * node : tree.nodes) {
        node->concrete_tree_graphics->set_show_delta(show_delta);
    }

    concrete_tree_scene->update();
}

bool GraphicsLinkCutTree::is_show_delta()
{
    return this->show_delta;
}

QGraphicsScene *GraphicsLinkCutTree::get_abstract_tree_scene()
{
    return this->abstract_tree_scene;
}

QGraphicsScene *GraphicsLinkCutTree::get_concrete_tree_scene()
{
    return this->concrete_tree_scene;
}

void GraphicsLinkCutTree::activate_concrete_tree_scene()
{
    this->active_scene_type = "concrete";
    update_scene();
}

void GraphicsLinkCutTree::activate_abstract_tree_scene()
{
    this->active_scene_type = "abstract";
    update_scene();
}

const QString &GraphicsLinkCutTree::get_current_scene_type()
{
    return this->active_scene_type;
}

void GraphicsLinkCutTree::animate_scene()
{
    if (this->active_scene_type == "concrete") {
        for (Node * node : tree.nodes) {
            node->concrete_tree_graphics->animate();
        }
        concrete_tree_scene->update();
    } else if (this->active_scene_type == "abstract") {
        for (Node * node : tree.nodes) {
            node->abstract.graphics->animate();
        }
        abstract_tree_scene->update();
    }
}
