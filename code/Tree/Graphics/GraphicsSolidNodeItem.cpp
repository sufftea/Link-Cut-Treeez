#include "Tree/Graphics/GraphicsSolidNodeItem.h"
#include "Tree/Node.h"
#include "Helpers/Colors.h"


GraphicsSolidNodeItem::GraphicsSolidNodeItem(Node * my_node, QGraphicsScene *my_scene)
    : pix_node(QSize(node_size_px, node_size_px))
{
    this->my_node = my_node;
    this->my_scene = my_scene;


    pix_node.fill(Qt::transparent);

    QPainter painter(&pix_node);
//    painter.fillRect(pix_node.rect(), QBrush(Qt::TransparentMode));
    painter.setRenderHint(QPainter::RenderHint::Antialiasing);
    QPen white_pen(MyColors::white);
    white_pen.setWidth(3);
    painter.setPen(white_pen);

    QFont font;
    font.setPixelSize(25);
    painter.setFont(font);

    painter.setBrush(MyColors::blue);
    painter.drawEllipse(QRect(2, 2, node_size_px - 4, node_size_px - 4));

    painter.drawText(QRect(0, 0, node_size_px, node_size_px),
                      Qt::AlignHCenter | Qt::AlignVCenter,
                      QString::number(my_node->displayed_value));
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
        qreal v = movement_anim.get_value();
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
                  b, b);
}

void GraphicsSolidNodeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPen white_pen(MyColors::white);
    white_pen.setWidth(3);
    painter->setPen(white_pen);

    // draw node's parent line
    // either just a parant edge [2] or a path-parent pointer [1]
    if (this->my_node->is_solid_root()) {
        if (!this->my_node->is_abstract_root()) {
            // draw the path-parent pointer

            QPen red_pen(MyColors::red);
            red_pen.setStyle(Qt::DotLine);
            red_pen.setWidth(3);
            painter->setPen(red_pen);

            QPoint offset(GraphicsSolidNodeItem::node_size_px / 2,
                          GraphicsSolidNodeItem::node_size_px / 2);

            QPainterPath path_parent_path = PathCreator::create_path(this->pos().toPoint() + offset,
                                                         this->my_node->parent->graphics->pos().toPoint() + offset,
                                                         my_scene,
                                                         3);
            path_parent_path.translate(-this->pos());
            painter->drawPath(path_parent_path);

            // draw an arrow at the end of the path
            red_pen.setStyle(Qt::PenStyle::SolidLine);
            painter->setPen(red_pen);
            painter->setBrush(MyColors::red);

            QPolygonF arrow({
                              QPointF(-13, 0),
                              QPointF(0, -5),
                              QPointF(0, 5)
                          });

            qreal angle = -path_parent_path.angleAtPercent(0);
            QMatrix rot;
            rot.rotate(angle);
            arrow = rot.map(arrow);

            arrow.translate(path_parent_path.elementAt(0));
            painter->drawPolygon(arrow);
        }
    } else {
        // draw the edge
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

        painter->drawLine(QLineF(a, b));
    }

    // draw the node
    painter->drawPixmap(0, 0, this->pix_node);
}

