#ifndef GRAPHICSNODEITEM_H
#define GRAPHICSNODEITEM_H

#include <QGraphicsItem>

#include "Tree/Graphics/Helpers/animation.h"

class GraphicsLinkCutTree;

class GraphicsNodeItem : public QGraphicsItem
{
protected:
    QPointF last_pos = QPointF(0, 0);
    QPointF next_pos = QPointF(0, 0);

    GraphicsLinkCutTree *graphics_tree;

public:
    Animation movement_anim;


    GraphicsNodeItem(GraphicsLinkCutTree *graphics_tree);
    ~GraphicsNodeItem() override;


    void animate();
//    virtual void update_pixmap()=0;
};

#endif // GRAPHICSNODEITEM_H
