#include "GraphicsAbstractNodeItem.h"
#include "Tree/Graphics/Helpers/AbstractNode.h"
#include "Tree/Node.h"

GraphicsAbstractNodeItem::GraphicsAbstractNodeItem(AbstractNode *my_abstract_node)
    : pix(node_size_px, node_size_px)
{
    this->my_abstract_node = my_abstract_node;
    update_pixmap();
}

void GraphicsAbstractNodeItem::update_pixmap()
{
    this->pix.fill(Qt::transparent);

    QPainter painter(&pix);
    painter.setRenderHint(QPainter::RenderHint::Antialiasing);

    QPen circle_pen(MyColors::white);
    circle_pen.setWidth(3);
    painter.setPen(circle_pen);

    QFont font;
    font.setPixelSize(27);
    painter.setFont(font);


    if (this->view_type == ViewType::normal) {
        painter.setBrush(MyColors::blue);
        painter.drawEllipse(QRect(5, 5, node_size_px - 10, node_size_px - 10));
    } else if (this->view_type == ViewType::user_selected) {
        QPen thicker_pen(MyColors::white);
        thicker_pen.setWidth(6);
        painter.setPen(thicker_pen);

        painter.setBrush(MyColors::red);
        painter.drawEllipse(QRect(3, 3, node_size_px - 6, node_size_px - 6));
    }

    QString text;
    text = QString::number(my_abstract_node->my_solid_node->value);

    QPen text_pen(MyColors::white);
    text_pen.setWidth(3);
    painter.setPen(text_pen);

    painter.drawText(QRect(0, 0, node_size_px, node_size_px),
                      Qt::AlignHCenter | Qt::AlignVCenter,
                      text);
}

void GraphicsAbstractNodeItem::update_position(int node_offset, int solid_depth)
{
    int pos_x = node_offset * GraphicsAbstractNodeItem::node_size_px * 0.8;
    int pos_y = solid_depth * GraphicsAbstractNodeItem::node_size_px * 1.2;

    this->last_pos = this->pos();
    this->next_pos = QPointF(pos_x, pos_y);

    if (this->pos() != next_pos) {
        movement_anim.start();
    }
}

void GraphicsAbstractNodeItem::set_view_type(GraphicsAbstractNodeItem::ViewType type)
{
    if (this->view_type != type) {
        this->view_type = type;
        update_pixmap();
    }
}

GraphicsAbstractNodeItem::ViewType GraphicsAbstractNodeItem::get_view_type()
{
    return this->view_type;
}

QRectF GraphicsAbstractNodeItem::boundingRect() const
{
    return QRectF(0, 0, this->node_size_px, this->node_size_px);
}

void GraphicsAbstractNodeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPen white_pen(MyColors::white);
    white_pen.setWidth(3);
    painter->setPen(white_pen);

    // draw the edge
    if (my_abstract_node->is_prefered_child()) {
        QPointF a = QPoint(0, 0);
        QPointF b = my_abstract_node->parent->graphics->pos() - this->pos();

        QPoint offset(node_size_px / 2,
                      node_size_px / 2);

        a += offset;
        b += offset;

        QVector2D ab(b.x() - a.x(), b.y() - a.y());


        QVector2D tang(-ab.y(), ab.x());
        tang.normalize();
        tang *= node_size_px / 2 - 5;

        QPointF a1 = a + tang.toPointF();
        QPointF b1 = b + tang.toPointF();
        QPointF a2 = a - tang.toPointF();
        QPointF b2 = b - tang.toPointF();

        painter->drawLine(a1, b1);
        painter->drawLine(a2, b2);

    }

    if (this->my_abstract_node->parent != nullptr) {
        QPointF a = QPoint(0, 0);
        QPointF b = my_abstract_node->parent->graphics->pos() - this->pos();

        QPoint offset(node_size_px / 2,
                      node_size_px / 2);

        a += offset;
        b += offset;

        QVector2D ab(b.x() - a.x(), b.y() - a.y());
        QVector2D ba(a.x() - b.x(), a.y() - b.y());

        ab.normalize();
        ba.normalize();

        ab *= node_size_px / 2;
        ba *= node_size_px / 2;

        a += ab.toPoint();
        b += ba.toPoint();

        painter->drawLine(QLineF(a, b));
    }

    // draw the node
    painter->drawPixmap(0, 0, this->pix);
}
