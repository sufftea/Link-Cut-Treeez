#ifndef GRAPHICSLINCCUTTREE_H
#define GRAPHICSLINCCUTTREE_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>

#include "Tree/LinkCutTree.h"
#include "Tree/sequence.h"


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

private slots:
    void animate_scene();
};

#endif // GRAPHICSLINCCUTTREE_H