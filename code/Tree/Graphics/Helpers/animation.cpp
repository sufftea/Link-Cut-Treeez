#include "Tree/Graphics/Helpers/Animation.h"

Animation::Animation()
{

}

qreal Animation::get_value(bool dont_increment)
{
    if (!is_active) {
        return 0;
    }

    if (!dont_increment) {
        if (t < 1) {
            t += inc;
        } else {
            is_active = false;
        }
    }

    qreal v = t;
    if (is_inversed) {
        v = 1 - v;
    }

    qreal res = easing_curve(v);
    if (res > 1) res = 1;
    if (res < 0) res = 0;

    return res;
}

void Animation::set_reversed(bool is_inversed)
{
    this->is_inversed = is_inversed;
}

void Animation::set_easing_curve(std::function<qreal(qreal)> easing_curve)
{
    this->easing_curve = easing_curve;
}

void Animation::start()
{
    is_active = true;
    t = 0;
}

void Animation::stop()
{
    is_active = false;
    t = 1;
}

bool Animation::get_is_active()
{
    return this->is_active;
}

double Animation::linear(qreal t)
{
    return t;
}

double Animation::ease_out_cubic(qreal t)
{
    return 1 - pow(1 - t, 3);
}

double Animation::ease_in(qreal t)
{
    return t;
}

double Animation::ease_in_out(double t)
{
    return t;
}
