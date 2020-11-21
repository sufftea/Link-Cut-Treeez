#ifndef ANIMATION_H
#define ANIMATION_H

#include <iostream>
#include <functional>
#include <QDebug>
#include <cmath>


class Animation
{
    double t = 1;
    double inc = 0.1;
    bool is_inversed = false;
    bool is_active = false;
    std::function<double(double)> easing_curve = Animation::linear;


public: 
    Animation();

    double get_value(bool dont_increment = false);
    void set_reversed(bool is_reversed);
    void set_easing_curve(std::function<double(double)> easing_curve);
    void start();
    void stop();
    bool get_is_active();


    // easing curves
    static double linear(double t);
    static double ease_out_cubic(double t);
    static double ease_in(double t);
    static double ease_in_out(double t);
};

#endif // ANIMATION_H
