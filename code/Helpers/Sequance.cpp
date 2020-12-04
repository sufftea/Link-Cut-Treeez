#include "Helpers/Sequance.h"

QString SequanceLog::text = "";
int SequanceLog::in = 0;


SequanceLog::SequanceLog()
{
    in = 0;
    text = "";
}

void SequanceLog::step_in()
{
    in++;
}

void SequanceLog::step_out()
{
    if (in > 0) {
        in--;
    }
}

void SequanceLog::add(const QString &action)
{
    text += QString("|  ").repeated(in) + action + "\n";
}

void SequanceLog::clear()
{
    text.clear();
}

const QString &SequanceLog::get_text()
{
    return text;
}
