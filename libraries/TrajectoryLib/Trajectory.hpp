// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#ifndef __TRAJECTORY_HPP__
#define __TRAJECTORY_HPP__

#include <vector>

namespace teo
{

class Trajectory
{
public:

    bool getX(const double movementTime, std::vector<double>& desiredX);

    bool getXdot(const double movementTime, std::vector<double>& desiredXdot);

    //bool generateLine(std::vector<double>& src, std::vector<double>& dest)
    //{
    //    return true;
    //}
};

}  // namespace teo

#endif  // __TRAJECTORY_HPP__