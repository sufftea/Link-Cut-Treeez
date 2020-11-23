#ifndef SEQUANCELOGGER_H
#define SEQUANCELOGGER_H

#include <QString>
#include <QDebug>

class SequanceLog
{
    static QString text;
    static int in;

public:

    SequanceLog();

    static void step_in();
    static void step_out();

    static void add(const QString & action);

    static void clear();

    static const QString & get_text();
};

#endif // SEQUANCELOGGER_H
