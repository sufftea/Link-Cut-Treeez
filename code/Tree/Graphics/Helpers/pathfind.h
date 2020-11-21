#ifndef PATHFIND_H
#define PATHFIND_H

#include <QHash>
#include <QVector>
#include <QPoint>
#include <QGraphicsScene>
#include <QVector2D>
#include <QDebug>
#include <QGraphicsItem>


inline uint qHash (const QPoint & key)
{
    return qHash (static_cast <qint64> (key.x () ) << 32 | key.y () );
}


class Pathfind
{
    struct Cell {
        QPoint pos = QPoint(-1, -1);
        QPoint prev = QPoint(-1, -1);
        int g = INT32_MAX;
        int f = INT32_MAX;
        int h = INT32_MAX;

        Cell(QPoint pos, QPoint prev, QPoint targ, int f);

        Cell(QPoint pos, QPoint prev, int g, int f, int h);

        Cell() {}
    };


    // puts [cell] into [opened] if the cell is not closed
    // and the new cell is better than the one inside [opened]
    // and the new cell doesn`t intersect anonther objecn
    // on the scene
    static void add_to_open(const Cell &cell,
                            QHash<QPoint, Cell> *opened,
                            QHash<QPoint, Cell> *closed,
                            QGraphicsScene *scene,
                            QPoint startingPoint);

public:
    static int step_length_px;


    static QList<QPointF> find_path(QPoint from,
                                    QPoint targ,
                                    QGraphicsScene * scene);
};

#endif // PATHFIND_H
