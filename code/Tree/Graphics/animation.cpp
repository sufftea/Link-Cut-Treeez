#include "animation.h"

Animation::Animation()
{

}

double Animation::get_value(bool dont_increment)
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

    double v = t;
    if (is_inversed) {
        v = 1 - v;
    }

    double res = easing_curve(v);
    if (res > 1) res = 1;
    if (res < 0) res = 0;

    return res;
}

void Animation::set_reversed(bool is_inversed)
{
    this->is_inversed = is_inversed;
}

void Animation::set_easing_curve(std::function<double (double)> easing_curve)
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

double Animation::linear(double t)
{
    return t;
}

double Animation::ease_out_cubic(double t)
{
    return 1 - pow(1 - t, 3);
}

double Animation::ease_in(double t)
{
    return t;
}

double Animation::ease_in_out(double t)
{
    return t;
}
