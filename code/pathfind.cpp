#include "pathfind.h"

int Pathfind::cell_size_px = 35;


void Pathfind::add_to_open(const Cell &cell,
                           QHash<QPoint, Cell> *opened,
                           QHash<QPoint, Cell> *closed,
                           QGraphicsScene * scene)
{
    if (scene->itemAt(cell.pos, QTransform()) != nullptr) {
        return;
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

QVector<QPoint> Pathfind::find_path(QPoint from, QPoint targ, QGraphicsScene *scene)
{
    QHash<QPoint, Cell> opened;
    QHash<QPoint, Cell> closed;

    opened.insert(from, Cell(from, from, targ, 0));
    bool target_found_flag = false;

//    qDebug() << "from: " << from << "\tto: " << targ;

    while (!opened.isEmpty() && !target_found_flag) {
        Cell curr = opened.begin().value();

        // cell with minimal h cost
        for (const Cell &c : opened) {
            if (c.h < curr.h || (c.h == curr.h && c.g < curr.g)) {
                curr = c;
            }
        }

//        qDebug() << "\tcurr: " << curr.pos;

        // to prevent infinite loop
        if (curr.f > 40) {
            opened.remove(curr.pos);
            break;
        }

        QVector<QPoint> neighbours = {
            curr.pos + QPoint( cell_size_px,  0),
//            curr.pos + QPoint( cell_size_px,  cell_size_px),
            curr.pos + QPoint( 0,             cell_size_px),
//            curr.pos + QPoint(-cell_size_px,  cell_size_px),
            curr.pos + QPoint(-cell_size_px,  0),
//            curr.pos + QPoint(-cell_size_px, -cell_size_px),
            curr.pos + QPoint( 0,            -cell_size_px),
//            curr.pos + QPoint( cell_size_px, -cell_size_px)
        };

        for (QPoint nei : neighbours) {
            if (QVector2D(nei - targ).length() < cell_size_px) {
                target_found_flag = true;
                closed[targ] = Cell(targ, curr.pos, targ, curr.f + 1);
                break;
            }

            add_to_open(Cell(nei, curr.pos, targ, curr.f + 1),
                        &opened, &closed,
                        scene);
        }

        opened.remove(curr.pos);
        closed[curr.pos] = curr;
    }


//    qDebug() << "restore the path";
    // restore the path
    QVector<QPoint> path;
    if (closed.contains(targ)) {
        QPoint curr_pos = closed[targ].pos;
//        qDebug() << "\tcurrent: " << curr_pos;
        while (QVector2D(curr_pos - from).length() >= cell_size_px) {
            path.push_back(curr_pos);
            curr_pos = closed[curr_pos].prev;
        }
        path.push_back(from);
    } else {
//        qDebug() << "\tdirect path";
        path.push_back(targ);
        path.push_back(from);
    }


    return path;
}

void Pathfind::set_cell_size_px(int px)
{
    cell_size_px = px;
}

Pathfind::Cell::Cell(QPoint pos, QPoint prev, QPoint targ, int f)
{
    this->pos = pos;
    this->prev = prev;

    this->f = f;
    this->g = QVector2D(targ - pos).length();
    this->h = g + f;
}

Pathfind::Cell::Cell(QPoint pos, QPoint prev, int g, int f, int h)
{
    this->pos = pos;
    this->prev = prev;
    this->g = g;
    this->f = f;
    this->h = h;
}
