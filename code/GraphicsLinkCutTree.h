#ifndef GRAPHICSLINCCUTTREE_H
#define GRAPHICSLINCCUTTREE_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>

#include "LinkCutTree.h"
#include "sequence.h"


class GraphicsLinkCutTree : public QObject
{
    Q_OBJECT

    QTimer * animation_timer;


public:   
    GraphicsLinkCutTree();
    virtual ~GraphicsLinkCutTree();

    QGraphicsScene * scene;
    LinkCutTree tree = LinkCutTree();

    void update_scene();
    void init(int size);
    void set_movement_easing_curve(std::function<double(double)> f);

public slots:
    void animate_scene();
};

#endif // GRAPHICSLINCCUTTREE_H
