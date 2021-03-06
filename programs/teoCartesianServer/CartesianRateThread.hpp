// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#ifndef __CARTESIAN_RATE_THREAD__
#define __CARTESIAN_RATE_THREAD__

#include <vector>
#include <fstream>

#include <math.h>  //-- fabs

#include <yarp/os/RateThread.h>
#include <yarp/dev/ControlBoardInterfaces.h>
#include <yarp/os/ResourceFinder.h>

#include "ColorDebug.hpp"
#include "ICartesianSolver.h"

#define DEFAULT_MS 50  // [ms], overwritten by parent DEFAULT_PT_MODE_MS.
#define DEFAULT_GAIN 0
#define MAX_ANG_VEL 7.5

namespace teo
{

/**
 * @ingroup teoCartesianServer
 *
 * @brief The actual \ref teoCartesianServer periodical thread.
 *
 */
class CartesianRateThread : public yarp::os::RateThread
{
public:
    /** Set the Thread Rate in the class constructor. */
    CartesianRateThread();

    /** Initialization method. */
    virtual bool threadInit();

    /** Loop function. This is the thread itself. */
    virtual void run();

    /** load */
    bool load(const std::string& fileName);

    /** stat */
    bool stat(std::vector<double>& stat);

    /** inv */
    bool inv(std::vector<double> &xd, std::vector<double> &q);

    /** movj */
    bool movj(std::vector<double> &xd);

    /** checkMotionDone */
    bool checkMotionDone(bool* flag)     {
        iPositionControl->checkMotionDone(flag);
    }

    /** Solver stuff */
    int solverNumLinks;
    teo::ICartesianSolver *solver;

    /** Robot stuff */
    int numMotors;
    yarp::dev::IEncoders *iEncoders;
    yarp::dev::IVelocityControl *iVelocityControl;
    yarp::dev::IPositionControl *iPositionControl;

    void setRf(yarp::os::ResourceFinder* rf) {
        this->rf = rf;
    }

protected:
    yarp::os::ResourceFinder *rf;

    /** File stuff */
    std::ifstream ifs;
    int lineCount;

    enum State
    {
        STOPPED,
        PTMODE,
        MOVJ
    };
    State currentState;

    /** Robot control stuff */
    std::vector< double > qReal;
    std::vector< double > qDotCmd;
    std::vector< double > xReal;
    std::vector< double > oReal;
    std::vector< double > xDesired;
    std::vector< double > xDotDesired;
    std::vector< double > xDotCmd;
    std::vector< double > xError;
};

}  // namespace teo

#endif  // __CARTESIAN_RATE_THREAD__

