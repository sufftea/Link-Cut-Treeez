#ifndef GRAPHICSLINCCUTTREE_H
#define GRAPHICSLINCCUTTREE_H

#include <QGraphicsScene>
#include "LinkCutTree.h"
#include "sequence.h"

class GraphicsLinkCutTree
{
public:   
    GraphicsLinkCutTree(int size);

    QGraphicsScene * scene;
    LinkCutTree tree;

    void update_scene();
};

#endif // GRAPHICSLINCCUTTREE_H
