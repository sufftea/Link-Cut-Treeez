#include "Tree/Graphics/graphicsnode.h"
#include "Tree/Node.h"


GraphicsSolidNodeItem::GraphicsSolidNodeItem(Node * my_node, QGraphicsScene *my_scene)
{
    this->my_node = my_node;
    this->my_scene = my_scene;
}

GraphicsSolidNodeItem::~GraphicsSolidNodeItem()
{

}

void GraphicsSolidNodeItem::update_position(int node_offset, int solid_depth)
{
    int node_x = node_offset * GraphicsSolidNodeItem::node_width_px;
    int node_y = solid_depth * GraphicsSolidNodeItem::node_width_px;

    this->last_pos = this->pos();
    this->next_pos = QPointF(node_x, node_y);

    if (this->pos() != next_pos) {
        movement_anim.start();
    }
}

void GraphicsSolidNodeItem::animate()
{
    // animate the position
    if (movement_anim.get_is_active()) {
        double v = movement_anim.get_value();
        QPointF m = (next_pos - last_pos) * v;
        this->setPos(last_pos + m);
    }
}

void GraphicsSolidNodeItem::set_movement_easing_curve(std::function<double (double)> f)
{
    this->movement_anim.set_easing_curve(f);
}

void GraphicsSolidNodeItem::set_my_scene(QGraphicsScene *scene)
{
    this->my_scene = scene;
}




QRectF GraphicsSolidNodeItem::boundingRect() const
{
    return QRectF(0, 0,
                  GraphicsSolidNodeItem::node_width_px,
                  GraphicsSolidNodeItem::node_width_px);
}

void GraphicsSolidNodeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPen black_pen(Qt::black);
    black_pen.setWidth(3);
    painter->setPen(black_pen);


    QFont font;
    font.setPixelSize(25);
    painter->setFont(font);

    painter->drawText(this->boundingRect(),
                      Qt::AlignHCenter | Qt::AlignVCenter,
                      QString::number(my_node->displayed_value));

    painter->drawEllipse(this->boundingRect());


    // draw node's parent line

    if (this->my_node->is_solid_root()) {
        if (!this->my_node->is_abstract_root()) {
            // draw the path parent connection
            // Ideally, make it not just a straight line

            QPointF a = QPoint(0, 0);
            QPointF b = this->my_node->parent->graphics->pos() - this->pos();


            QPoint offset(GraphicsSolidNodeItem::node_width_px / 2,
                          GraphicsSolidNodeItem::node_width_px / 2);

            a += offset;
            b += offset;

            QVector2D ab(b.x() - a.x(), b.y() - a.y());
            QVector2D ba(a.x() - b.x(), a.y() - b.y());

            ab.normalize();
            ba.normalize();

            ab *= GraphicsSolidNodeItem::node_width_px / 2;
            ba *= GraphicsSolidNodeItem::node_width_px / 2;

            a += ab.toPoint();
            b += ba.toPoint();

            QPen red_pen(Qt::red, 2, Qt::DotLine);
            painter->setPen(red_pen);


            // draw path parent pointer
            //            QVector<QPoint> path = Pathfind::find_path(this->pos().toPoint() + offset,
            //                                                       this->my_node->parent->graphics.pos().toPoint() + offset,
            //                                                       my_scene);
            //            if (path.size() >= 3) {
            //                QPainterPath painter_path(path[0]);

            //                for (int i = 2; i < path.size(); ++i) {
            //                    // only if there's a corner
            //                    if (path[i-2].x() != path[i].x() && path[i-2].y() != path[i].y()) {
            //                        painter_path.quadTo(path[i-1], path[i]);
            //                    } else {
            //                        painter_path.lineTo(path[i]);
            //                    }
            //                }

            //                painter_path.translate(-this->pos());
            //                painter->drawPath(painter_path);
            //            } else if (path.size() == 2) {
            //                painter->drawLine(path[0] - this->pos().toPoint(), path[1] - this->pos().toPoint());
            //            }
        }
    } else {
        // draw the edge connecting the node to it's parent
        QPointF a = QPoint(0, 0);
        QPointF b = this->my_node->parent->graphics->pos() - this->pos();


        QPoint offset(GraphicsSolidNodeItem::node_width_px / 2,
                      GraphicsSolidNodeItem::node_width_px / 2);

        a += offset;
        b += offset;

        QVector2D ab(b.x() - a.x(), b.y() - a.y());
        QVector2D ba(a.x() - b.x(), a.y() - b.y());

        ab.normalize();
        ba.normalize();

        ab *= GraphicsSolidNodeItem::node_width_px / 2;
        ba *= GraphicsSolidNodeItem::node_width_px / 2;

        a += ab.toPoint();
        b += ba.toPoint();

        QPen black_pen(Qt::black);
        black_pen.setWidth(2);
        painter->setPen(black_pen);

        painter->drawLine(QLineF(a, b));
    }
}
