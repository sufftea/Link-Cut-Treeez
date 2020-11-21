#ifndef PATHSMOOTHER_H
#define PATHSMOOTHER_H

#include <QPainterPath>


class PathSmoother
{
private:
    /**
     * @brief uses the incoming curve vertex coordinates to create a smooth curve.
    *
     * @param points vertices coordinate array of the curve,
     * points[i+0] is the x coordinate of the ith point,
     * points[i+1] is the y coordinate of the i point
     * @param closed Whether the curve is closed, the default is not closed
     * @param tension density, the default is 0.5
     * @param numberOfSegments The number of line segments between 2 vertices of the smooth curve, the default is 16
     * @return QPainterPath for smooth curves
    */
    static QPainterPath generateSmoothCurve(QList<double>points,
                                            bool closed = false,
                                            double tension = 0.5,
                                            int numberOfSegments = 16);


public:    
    /**
     * @brief generateSmoothCurve overloaded function
    */
    static QPainterPath generateSmoothCurve(QList<QPointF> points,
                                            bool closed = false,
                                            double tension = 0.5,
                                            int numberOfSegments = 16);


};

#endif // PATHSMOOTHER_H
