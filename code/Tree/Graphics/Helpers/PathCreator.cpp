#include "Tree/Graphics/Helpers/PathCreator.h"
#include "Tree/Graphics/GraphicsSolidNodeItem.h"
#include "Tree/Graphics/Helpers/PathSmoother.h"

int PathCreator::step_length_px = 37;


void PathCreator::add_to_open(const Cell &cell,
                           QHash<QPoint, Cell> *opened,
                           QHash<QPoint, Cell> *closed,
                           const QGraphicsScene * scene, QPoint startingPoint)
{
    QGraphicsItem * obst = scene->itemAt(cell.pos, QTransform());
    if (obst != nullptr) {
        if (QVector2D(obst->pos() - startingPoint).length() > GraphicsSolidNodeItem::node_bound_size_px) {
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

QPainterPath PathCreator::create_path(QPoint from, QPoint targ, const QGraphicsScene *scene, int skip_points)
{
    QHash<QPoint, Cell> opened;
    QHash<QPoint, Cell> closed;

    opened.insert(from, Cell(from, from, targ, 0));
    bool target_found_flag = false;


    while (!opened.isEmpty() && !target_found_flag) {
        Cell curr = opened.begin().value();

        // cell with minimal h cost
        for (const Cell &c : opened) {
            if (c.h < curr.h || (c.h == curr.h && c.g < curr.g)) {
                curr = c;
            }
        }

        // to prevent infinite loop
        if (curr.f > 40) {
            opened.remove(curr.pos);
            break;
        }

        // I added some randomization (+-2) in an attempt
        // to prevent different paths from overlapping with
        // each other.
        // They still might but that's more unlikely.
        QVector<QPoint> neighbours = {
            curr.pos + QPoint( step_length_px,  4),
            curr.pos + QPoint( 4             , step_length_px),
            curr.pos + QPoint(-step_length_px,  -4),
            curr.pos + QPoint( -4            , -step_length_px),
            curr.pos + QPoint( step_length_px / 2 + 4,  step_length_px / 2 - 4),
            curr.pos + QPoint(-step_length_px / 2 - 4, -step_length_px / 2 + 4),
            curr.pos + QPoint(-step_length_px / 2 - 4,  step_length_px / 2 - 4),
            curr.pos + QPoint( step_length_px / 2 + 4, -step_length_px / 2 + 4)
        };

        for (QPoint nei : neighbours) {
            if (QVector2D(nei - targ).length() < GraphicsSolidNodeItem::node_bound_size_px) {
                target_found_flag = true;
                closed[targ] = Cell(targ, curr.pos, targ, curr.f + 1);
            }

            add_to_open(Cell(nei, curr.pos, targ, curr.f + 1),
                        &opened, &closed,
                        scene,
                        from);
        }

        opened.remove(curr.pos);
        closed[curr.pos] = curr;
    }


    // restore the path
    QList<QPointF> path;
    if (closed.contains(targ)) {
        QPoint curr_pos = closed[targ].pos;

        int i = 0;
        while (curr_pos != from) {
            if ( ! (i++ % (skip_points + 1)) ) {
                path.push_back(curr_pos);
            }
            curr_pos = closed[curr_pos].prev;
        }

        path.push_back(from);
    } else {
        path.push_back(targ);
        path.push_back(from);
    }


//    if (! path.isEmpty()) {
//        path.removeFirst();
//    }

    if (path.length() < 2) {
        QPainterPath path(targ);
        path.lineTo(from);
        return path;
    }
    return PathSmoother::generateSmoothCurve(path);
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
