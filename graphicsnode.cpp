#include "graphicsnode.h"
#include "Node.h"

GraphicsNodeItem::GraphicsNodeItem(Node * my_node, int displayed_value)
{
    this->my_node = my_node;
    this->displayed_value = displayed_value;
}

GraphicsNodeItem::GraphicsNodeItem(int relative_to_parent_pos, Node *my_node, int displayed_value)
{
    this->relative_to_parent_pos = relative_to_parent_pos;
    this->my_node = my_node;
    this->displayed_value = displayed_value;
}

void GraphicsNodeItem::update_position(QGraphicsScene *scene, int offset, int solid_depth)
{
    int node_x = (offset + this->relative_to_parent_pos) * GraphicsNodeItem::element_width_px;
    int node_y = solid_depth * GraphicsNodeItem::element_width_px;
    node_x -= GraphicsNodeItem::element_width_px / 2;
    node_y -= GraphicsNodeItem::element_width_px / 2;


    this->setPos(node_x, node_y);
//    scene->addItem(this);


    if (my_node->is_solid_root()) {
        // draw the path parent connection
        // Ideally, make it not just a straight line

        if (this->parent_line != nullptr) {
            scene->removeItem(this->parent_line);

            delete this->parent_line;
            this->parent_line = nullptr;
        }

    } else {
        // draw the edge connecting the node to it's parent
        QPointF a = this->pos();
        QPointF b = my_node->parent->graphics->pos();


        QPoint offset(GraphicsNodeItem::element_width_px / 2,
                      GraphicsNodeItem::element_width_px / 2);

        a += offset;
        b += offset;

        QVector2D ab(b.x() - a.x(), b.y() - a.y());
        QVector2D ba(a.x() - b.x(), a.y() - b.y());

        ab.normalize();
        ba.normalize();

        ab *= GraphicsNodeItem::element_width_px;
        ba *= GraphicsNodeItem::element_width_px;

        a += ab.toPoint();
        b += ba.toPoint();

        QPen black_pen(Qt::black);
        black_pen.setWidth(4);

        if (this->parent_line == nullptr) {
            this->parent_line = scene->addLine(QLineF(a, b), black_pen);
        } else {
            this->parent_line->setLine(QLineF(a, b));
        }
    }
}

QRectF GraphicsNodeItem::boundingRect() const
{
    return QRectF(0,0, element_width_px, element_width_px);
}

void GraphicsNodeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{   
    QPen black_pen(Qt::black);
    black_pen.setWidth(5);
    painter->setPen(black_pen);


    QFont font;
    font.setPixelSize(25);
    painter->setFont(font);
    painter->drawText(this->boundingRect(),
                      Qt::AlignHCenter | Qt::AlignVCenter,
                      QString::number(this->displayed_value));

    painter->drawEllipse(this->boundingRect());
}
