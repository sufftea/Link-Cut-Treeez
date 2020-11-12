#include "graphicsnode.h"
#include "Node.h"

GraphicsSolidNodeItem::GraphicsSolidNodeItem(Node * my_node, int displayed_value)
{
    this->my_node = my_node;
    this->displayed_value = displayed_value;
}

GraphicsSolidNodeItem::GraphicsSolidNodeItem(int relative_to_parent_pos, Node *my_node, int displayed_value)
    : GraphicsSolidNodeItem(my_node, displayed_value)
{
    this->relative_to_solid_parent_pos = relative_to_parent_pos;
}

void GraphicsSolidNodeItem::update_position(int tree_offset, int solid_depth)
{
    int node_x = 0;
    int node_y = solid_depth * GraphicsSolidNodeItem::node_width_px;

    if (my_node->is_child()) {
        node_x = my_node->parent->graphics->pos().x()
                + relative_to_solid_parent_pos * GraphicsSolidNodeItem::node_width_px;
    } else {
        node_x = tree_offset * GraphicsSolidNodeItem::node_width_px;
    }

//    node_x -= GraphicsSolidNodeItem::node_width_px / 2;
//    node_y -= GraphicsSolidNodeItem::node_width_px / 2;

    this->setPos(node_x, node_y);
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
                      QString::number(this->displayed_value));

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

            painter->drawLine(QLineF(a, b));
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
