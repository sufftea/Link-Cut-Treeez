#include "GraphicsAbstractNodeItem.h"
#include "Tree/Graphics/Helpers/AbstractNode.h"
#include "Tree/Node.h"
#include "Tree/Graphics/GraphicsLinkCutTree.h"

GraphicsAbstractNodeItem::GraphicsAbstractNodeItem(AbstractNode *my_abstract_node, GraphicsLinkCutTree *graphics_tree)
    : GraphicsNodeItem(graphics_tree),
      pix(node_size_px, node_size_px)
{
    this->my_abstract_node = my_abstract_node;

    this->movement_anim.set_easing_curve(graphics_tree->get_animation_easing_curve());
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
    int pos_x = node_offset * GraphicsAbstractNodeItem::node_size_px * 1.1;
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
    white_pen.setWidth(4);
    painter->setPen(white_pen);

    // draw parent edge
    if (my_abstract_node->parent) {
        QPointF a = QPoint(0, 0);
        QPointF b = my_abstract_node->parent->graphics->pos() - this->pos();
        QPoint offset(node_size_px / 2,
                      node_size_px / 2);
        a += offset;
        b += offset;
        QVector2D ab(float(b.x() - a.x()), float(b.y() - a.y()));
        QVector2D ba(float(a.x() - b.x()), float(a.y() - b.y()));
        ab.normalize();
        ba.normalize();

        if (my_abstract_node->is_prefered_child()) {
            ab *= node_size_px / 2 + 5;
            ba *= node_size_px / 2 + 5;

            a += ab.toPoint();
            b += ba.toPoint();

            QPen red_pen(MyColors::red);
            red_pen.setWidth(14);
            painter->setPen(red_pen);
            painter->drawLine(QLineF(a, b));

            painter->setPen(white_pen);
        } else if (this->my_abstract_node->parent != nullptr) {
            ab *= node_size_px / 2;
            ba *= node_size_px / 2;

            a += ab.toPoint();
            b += ba.toPoint();

            painter->drawLine(QLineF(a, b));

        }
    }

    // draw the path info (min max sum)
    if ( ! my_abstract_node->my_solid_node->is_prefered_child()) {
        Node * root = my_abstract_node->my_solid_node->get_solid_root();

        QString text;
        text += "sum: " + QString::number(root->sum_agg);
        text += "\nmin: " + QString::number(root->min_agg);
        text += "\nmax: " + QString::number(root->max_agg);

        painter->drawText(QRect(60, 0, 100, 100),
                          Qt::AlignLeft | Qt::AlignTop,
                          text);
    }

    // draw the node
    painter->drawPixmap(0, 0, this->pix);


}
