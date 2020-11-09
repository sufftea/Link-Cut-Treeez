#ifndef SEQUANCELOGGER_H
#define SEQUANCELOGGER_H

#include <QString>
#include <QDebug>

class Sequence
{
    static QString text;
    static int in;

public:

    Sequence();

    static void step_in();
    static void step_out();

    static void add(const QString & action);

    static void clear();

//    const QString & get_text();
    static const QString & get_text();
};

#endif // SEQUANCELOGGER_H
