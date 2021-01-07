#ifndef GRAPHICSNODEITEM_H
#define GRAPHICSNODEITEM_H

#include <QGraphicsItem>

#include "Tree/Graphics/Helpers/Animation.h"

class GraphicsNodeItem : public QGraphicsItem
{
protected:
    QPointF last_pos = QPointF(0, 0);
    QPointF next_pos = QPointF(0, 0);

public:
    Animation movement_anim;


    GraphicsNodeItem();
    ~GraphicsNodeItem() override;


    void animate();
//    virtual void update_pixmap()=0;
};

#endif // GRAPHICSNODEITEM_H
