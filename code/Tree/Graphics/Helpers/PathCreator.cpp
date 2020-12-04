#include "Tree/Graphics/Helpers/PathCreator.h"
#include "Tree/Graphics/GraphicsSolidNodeItem.h"
#include "Tree/Graphics/Helpers/PathSmoother.h"

int PathCreator::step_length_px = 25;


void PathCreator::add_to_opened(const Cell &cell,
                                QHash<QPoint, Cell> *opened,
                                QHash<QPoint, Cell> *closed,
                                const QGraphicsScene * scene,
                                QPoint startingPoint)
{
    QGraphicsItem * obst = scene->itemAt(cell.pos, QTransform());
    if (obst != nullptr) {
        if (!is_inside(cell.pos, startingPoint, GraphicsSolidNodeItem::node_bound_size_px / 2)) {
            return;
        }
    }

    if ( ! closed->contains(cell.pos)) {
        if (opened->contains(cell.pos)
                && ((*opened)[cell.pos].h < cell.h
                || ((*opened)[cell.pos].h == cell.h&& (*opened)[cell.pos].g <= cell.g)))
        {
            return;
        }

        (*opened)[cell.pos] = cell;
    }
}

bool PathCreator::is_inside(QPoint point, QPoint item_pos, int item_size)
{
    return QVector2D(point - item_pos).length() < item_size;
}

QPainterPath PathCreator::create_path(QPoint from, QPoint targ, const QGraphicsScene *scene, int skip_points)
{
    from.rx() += (from.x() + from.y()) % 3;
    from.ry() += (from.x() + from.y()) % 3;

    QHash<QPoint, Cell> opened;
    QHash<QPoint, Cell> closed;

    opened.insert(from, Cell(from, from, targ, 0));
    bool target_found_flag = false;


    while (!opened.isEmpty() && !target_found_flag) {
        // find cell with minimal h-cost
        Cell curr = opened.begin().value();
        for (const Cell &c : opened) {
            if (c.h < curr.h || (c.h == curr.h && c.g < curr.g)) {
                curr = c;
            }
        }

        if (closed.size() > 200) {
            closed[targ] = Cell(targ, curr.pos, targ, curr.f + 1);
            break;
        }

        // +- 2 is to prevent different paths from overlapping with
        // each other.
        QVector<QPoint> neighbours = {
            curr.pos + QPoint( step_length_px,  2),
            curr.pos + QPoint( 2             , step_length_px),
            curr.pos + QPoint(-step_length_px,  -2),
            curr.pos + QPoint( -2            , -step_length_px),
        };

        for (QPoint nei : neighbours) {
            if (is_inside(nei, targ, GraphicsSolidNodeItem::node_size_px)) {
                target_found_flag = true;
                closed[targ] = Cell(targ, curr.pos, targ, curr.f + 1);
            }

            add_to_opened(Cell(nei, curr.pos, targ, curr.f + 1),
                          &opened, &closed,
                          scene,
                          from);
        }

        opened.remove(curr.pos);
        closed[curr.pos] = curr;
    }



    // restore the path
    QList<QPointF> path;
    path.push_back(targ);

    QPoint curr_pos = closed[targ].prev;
    int i = 0;
    while (curr_pos != from) {
        if ( ! (i++ % (skip_points + 1)) ) {
            path.push_back(curr_pos);
        }

        curr_pos = closed[curr_pos].prev;

        if (i > 70) {
            break;
        }
    }
    path.push_back(from);


    // path must should stop some distance away
    // from the node it leads to.
    QPointF a = targ;
    QPointF b = path[1];

    QVector2D offset(b - a);
    offset.normalize();
    offset *= GraphicsSolidNodeItem::node_size_px / 2 + 13;

    a += offset.toPointF();

    path[0] = a;

    QPainterPath res = PathSmoother::generateSmoothCurve(path);
    return res;
}

PathCreator::Cell::Cell(QPoint pos, QPoint prev, QPoint targ, int f)
{
    this->pos = pos;
    this->prev = prev;

    this->f = f;
    this->g = QVector2D(targ - pos).length();
    this->h = g + f;
}

PathCreator::Cell::Cell(QPoint pos, QPoint prev, int g, int f, int h)
{
    this->pos = pos;
    this->prev = prev;
    this->g = g;
    this->f = f;
    this->h = h;
}
