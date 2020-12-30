#include "Helpers/Sequence.h"

QString SequenceLog::text = "";
int SequenceLog::in = 0;


SequenceLog::SequenceLog()
{
    in = 0;
    text = "";
}

void SequenceLog::step_in()
{
    in++;
}

void SequenceLog::step_out()
{
    if (in > 0) {
        in--;
    }
}

void SequenceLog::add(const QString &action)
{
    text += QString("|  ").repeated(in) + action + "\n";
}

void SequenceLog::clear()
{
    text.clear();
}

const QString &SequenceLog::get_text()
{
    return text;
}
