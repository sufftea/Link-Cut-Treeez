#ifndef ANIMATION_H
#define ANIMATION_H

#include <iostream>
#include <functional>
#include <QDebug>
#include <cmath>


class Animation
{
    qreal t = 1;
    qreal inc = 0.1;
    bool is_inversed = false;
    bool is_active = false;
    std::function<qreal(qreal)> easing_curve = Animation::linear;


public: 
    Animation();

    qreal get_value(bool dont_increment = false);
    void set_reversed(bool is_reversed);
    void set_easing_curve(std::function<qreal(qreal)> easing_curve);
    void start();
    void stop();
    bool get_is_active();


    // easing curves
    static qreal linear(qreal t);
    static qreal ease_out_cubic(qreal t);
    static qreal ease_in(qreal t);
    static qreal ease_in_out(qreal t);
};

#endif // ANIMATION_H
