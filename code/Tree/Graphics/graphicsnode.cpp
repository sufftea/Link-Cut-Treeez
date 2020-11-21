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
    int node_x = node_offset * GraphicsSolidNodeItem::node_size_px;
    int node_y = solid_depth * GraphicsSolidNodeItem::node_size_px;

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

int GraphicsSolidNodeItem::traverse_and_update_position(int offset, int solid_depth)
{
    int width = 0;
    if (my_node->left != nullptr) {
        width += my_node->left->graphics->traverse_and_update_position(offset, solid_depth + 1);
    }
    offset += width;

    this->update_position(offset, solid_depth);
    offset += 1;

    if (my_node->right != nullptr) {
        width += my_node->right->graphics->traverse_and_update_position(offset, solid_depth + 1);
    }

    return width + 1;
}




QRectF GraphicsSolidNodeItem::boundingRect() const
{
    int r = node_size_px;
    int b = node_bound_size_px;
    return QRectF(-(b - r) / 2, -(b - r) / 2,
                  r + (b - r) / 2,
                  r + (b - r) / 2);
}

void GraphicsSolidNodeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPen black_pen(Qt::black);
    black_pen.setWidth(3);
    painter->setPen(black_pen);


    QFont font;
    font.setPixelSize(25);
    painter->setFont(font);

    painter->drawText(QRect(0, 0, node_size_px, node_size_px),
                      Qt::AlignHCenter | Qt::AlignVCenter,
                      QString::number(my_node->displayed_value));

    painter->drawEllipse(QRect(0, 0, node_size_px, node_size_px));


    // draw node's parent line

    if (this->my_node->is_solid_root()) {
        if (!this->my_node->is_abstract_root()) {
            // draw the path parent connection
            // Ideally, make it not just a straight line

            QPointF a = QPoint(0, 0);
            QPointF b = this->my_node->parent->graphics->pos() - this->pos();


            QPoint offset(GraphicsSolidNodeItem::node_size_px / 2,
                          GraphicsSolidNodeItem::node_size_px / 2);

            a += offset;
            b += offset;

            QVector2D ab(b.x() - a.x(), b.y() - a.y());
            QVector2D ba(a.x() - b.x(), a.y() - b.y());

            ab.normalize();
            ba.normalize();

            ab *= GraphicsSolidNodeItem::node_size_px / 2;
            ba *= GraphicsSolidNodeItem::node_size_px / 2;

            a += ab.toPoint();
            b += ba.toPoint();

            QPen red_pen(Qt::red, 2, Qt::DotLine);
            painter->setPen(red_pen);


            //            draw path parent pointer
            QList<QPointF> path = Pathfind::find_path(this->pos().toPoint() + offset,
                                                       this->my_node->parent->graphics->pos().toPoint() + offset,
                                                       my_scene);
            if (path.length() >= 3) {
//                if (path.length() >= 3) {
//                    path.pop_back();
//                }
                QPainterPath painter_path = PathSmoother::generateSmoothCurve(path);
                painter_path.translate(-this->pos());
                painter->drawPath(painter_path);
            }
        }
    } else {
        // draw the edge connecting the node to it's parent
        QPointF a = QPoint(0, 0);
        QPointF b = this->my_node->parent->graphics->pos() - this->pos();


        QPoint offset(GraphicsSolidNodeItem::node_size_px / 2,
                      GraphicsSolidNodeItem::node_size_px / 2);

        a += offset;
        b += offset;

        QVector2D ab(b.x() - a.x(), b.y() - a.y());
        QVector2D ba(a.x() - b.x(), a.y() - b.y());

        ab.normalize();
        ba.normalize();

        ab *= GraphicsSolidNodeItem::node_size_px / 2;
        ba *= GraphicsSolidNodeItem::node_size_px / 2;

        a += ab.toPoint();
        b += ba.toPoint();

        QPen black_pen(Qt::black);
        black_pen.setWidth(2);
        painter->setPen(black_pen);

        painter->drawLine(QLineF(a, b));
    }
}

