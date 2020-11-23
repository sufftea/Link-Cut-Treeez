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


public:   
    GraphicsLinkCutTree();
    ~GraphicsLinkCutTree();


    QGraphicsScene * scene;
    LinkCutTree tree;

    void update_scene();
    void init(int size);
    void set_animation_easing_curve(std::function<double(double)> f);
    bool set_animation_speed(qreal p);
    GraphicsSolidNodeItem * solid_node_at(QPoint pos);

private slots:
    void animate_scene();
};

#endif // GRAPHICSLINCCUTTREE_H
