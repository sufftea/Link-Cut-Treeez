#ifndef GRAPHICSLINCCUTTREE_H
#define GRAPHICSLINCCUTTREE_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>

#include "Tree/LinkCutTree.h"
#include "Helpers/Sequance.h"


class GraphicsLinkCutTree : public QObject
{
    Q_OBJECT

    QTimer * animation_timer;
    bool show_delta = false;

public:   
    GraphicsLinkCutTree();
    ~GraphicsLinkCutTree();


    QGraphicsScene * scene;
    LinkCutTree tree;

    void init(int size);

    void update_scene();
    void set_animation_easing_curve(std::function<double(double)> f);
    bool set_animation_speed(qreal p);
    GraphicsSolidNodeItem * solid_node_at(QPoint pos);
    void unselect_all_nodes();

    void set_show_delta(bool show_delta);
    bool is_show_delta();

private slots:
    void animate_scene();
};

#endif // GRAPHICSLINCCUTTREE_H
