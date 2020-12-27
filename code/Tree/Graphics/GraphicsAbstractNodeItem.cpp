#include "GraphicsAbstractNodeItem.h"
#include "Tree/Graphics/Helpers/AbstractNode.h"
#include "Tree/Node.h"

GraphicsAbstractNodeItem::GraphicsAbstractNodeItem(AbstractNode *my_abstract_node)
{
    this->my_abstract_node = my_abstract_node;
    update_pixmap();
}

void GraphicsAbstractNodeItem::update_pixmap()
{
    this->pix.fill(Qt::transparent);

    QPainter painter(&pix);
    painter.setRenderHint(QPainter::RenderHint::Antialiasing);
    QPen white_pen(MyColors::white);
    white_pen.setWidth(3);
    painter.setPen(white_pen);

    QFont font;
    font.setPixelSize(27);
    painter.setFont(font);


    if (this->selection == GraphicsNodeItem::SelectionType::no_selection) {
        painter.setBrush(MyColors::blue);
        painter.drawEllipse(QRect(5, 5, node_size_px - 10, node_size_px - 10));
    } else if (this->selection == GraphicsNodeItem::SelectionType::user_selected) {
        painter.setBrush(MyColors::red);
        painter.drawEllipse(QRect(2, 2, node_size_px - 4, node_size_px - 4));
    } else if (this->selection == GraphicsNodeItem::SelectionType::selection0) {
        painter.setBrush(MyColors::light_red);
        painter.drawEllipse(QRect(2, 2, node_size_px - 4, node_size_px - 4));
    } else if (this->selection == GraphicsNodeItem::SelectionType::selection1) {
        painter.setBrush(MyColors::red);
        painter.drawEllipse(QRect(2, 2, node_size_px - 4, node_size_px - 4));
    }

    QString text;
    text = QString::number(my_abstract_node->my_solid_node->get_value());

    painter.drawText(QRect(0, 0, node_size_px, node_size_px),
                      Qt::AlignHCenter | Qt::AlignVCenter,
                      text);
}

void GraphicsAbstractNodeItem::update_position(int node_offset, int solid_depth)
{
    int pos_x = node_offset * GraphicsAbstractNodeItem::node_size_px * 0.5;
    int pos_y = solid_depth * GraphicsAbstractNodeItem::node_size_px * 1.1;

    this->last_pos = this->pos();
    this->next_pos = QPointF(pos_x, pos_y);

    if (this->pos() != next_pos) {
        movement_anim.start();
    }
}

QRectF GraphicsAbstractNodeItem::boundingRect() const
{
    return QRectF(0, 0, this->node_size_px, this->node_size_px);
}

void GraphicsAbstractNodeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPen white_pen(MyColors::white);
    white_pen.setWidth(5);
    painter->setPen(white_pen);

    // draw the edge
    if (this->my_abstract_node->parent != nullptr) {
        QPointF a = QPoint(0, 0);

        AbstractNode * p = my_abstract_node->parent;
        GraphicsAbstractNodeItem * g = p->graphics;
        QPointF b = g->pos() - this->pos();

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
    painter->drawPixmap(0, 0, this->pix);
}
