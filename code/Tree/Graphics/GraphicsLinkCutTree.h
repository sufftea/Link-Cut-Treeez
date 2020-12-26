#ifndef GRAPHICSLINCCUTTREE_H
#define GRAPHICSLINCCUTTREE_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>

#include "Tree/LinkCutTree.h"
#include "Helpers/Sequence.h"
#include "Tree/Graphics/Helpers/AbstractNode.h"


class GraphicsLinkCutTree : public QObject
{
    Q_OBJECT

    QTimer * animation_timer;
    bool show_delta = false;

    QGraphicsScene * abstract_tree_scene;
    QGraphicsScene * concrete_tree_scene;
    QString active_scene_type = "concrete";


    void update_concrete_tree_scene();
    void update_abstract_tree_scene();

public:   
    GraphicsLinkCutTree();
    ~GraphicsLinkCutTree();



    LinkCutTree tree;

    /*
     * Initializes a Link-cut tree of size [size] and all the graphics for it.
     * If there already is a tree, deletes it.
    */
    void init(int size);

    /*
     * Must be called every time a change happens to the tree.
     * Traverses all the nodes in the tree and sets their new positions.
     *
     * The GraphicsNodes will be animated to move from their last position to
     * the new one.
    */
    void update_scene();
    /*
     * Two following functions are applied to every GraphicsNode on the scene.
    */
    void set_animation_easing_curve(std::function<double(double)> f);
    bool set_animation_speed(qreal p);

    /*
     * Returns a refference to a node of a concrete tree at the [pos] or a
     * nullptr if there are no nodes.
    */
    GraphicsSolidNodeItem * solid_node_at(QPoint pos);

    void unselect_all_nodes();


    void set_show_delta(bool show_delta);
    bool is_show_delta();


    QGraphicsScene * get_abstract_tree_scene();
    QGraphicsScene * get_concrete_tree_scene();

    void activate_concrete_tree_scene();
    void activate_abstract_tree_scene();

private slots:
    /*
     * Calles next animation step for every node on the scene.
    */
    void animate_scene();
};

#endif // GRAPHICSLINCCUTTREE_H
