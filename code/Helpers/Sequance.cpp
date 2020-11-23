#include "Helpers/Sequance.h"

QString Sequence::text = "";
int Sequence::in = 0;


Sequence::Sequence()
{
    in = 0;
    text = "";
}

void Sequence::step_in()
{
    in++;
}

void Sequence::step_out()
{
    if (in > 0) {
        in--;
    }
}

void Sequence::add(const QString &action)
{
    text += QString("   ").repeated(in) + action + "\n";
}

void Sequence::clear()
{
    text.clear();
}

const QString &Sequence::get_text()
{
    return text;
}
