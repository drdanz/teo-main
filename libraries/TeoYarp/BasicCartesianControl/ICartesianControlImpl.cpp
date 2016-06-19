// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "BasicCartesianControl.hpp"

// ------------------- ICartesianControl Related ------------------------------------

bool teo::BasicCartesianControl::stat(std::vector<double> &x)
{
    std::vector<double> qCurrent(numRobotJoints);
    if ( ! iEncoders->getEncoders( qCurrent.data() ) )
    {
        CD_ERROR("getEncoders failed.\n");
        return false;
    }
    if ( ! iCartesianSolver->fwdKin(qCurrent,x) )
    {
        CD_ERROR("fwdKin failed.\n");
        return false;
    }
    return true;
}

// -----------------------------------------------------------------------------

bool teo::BasicCartesianControl::inv(const std::vector<double> &xd, std::vector<double> &q)
{
    std::vector<double> qCurrent(numRobotJoints);
    if ( ! iEncoders->getEncoders( qCurrent.data() ) )
    {
        CD_ERROR("getEncoders failed.\n");
        return false;
    }
    if ( ! iCartesianSolver->invKin(xd,qCurrent,q) )
    {
        CD_ERROR("invKin failed.\n");
        return false;
    }
    return true;
}

// -----------------------------------------------------------------------------