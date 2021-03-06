// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#ifndef __X_RPC_RESPONDER__
#define __X_RPC_RESPONDER__

#include <yarp/os/Port.h>
#include <yarp/os/BufferedPort.h>
#include <yarp/os/Time.h>

#include <yarp/dev/PolyDriver.h>
#include <yarp/dev/CartesianControl.h>
#include <yarp/dev/ControlBoardInterfaces.h>

#include "CartesianRateThread.hpp"

#define VOCAB_HELP VOCAB4('h','e','l','p')
#define VOCAB_LOAD VOCAB4('l','o','a','d')
#define VOCAB_STAT VOCAB4('s','t','a','t')
#define VOCAB_INV VOCAB3('i','n','v')
#define VOCAB_MOVJ VOCAB4('m','o','v','j')


namespace teo
{

/**
 * @ingroup teoCartesianServer
 *
 * @brief Implements an xRpcPort responder (callback on RPC).
 */
class TeoXRpcResponder : public yarp::os::PortReader
{
public:
    void setCartesianRateThread(CartesianRateThread* cartesianRateThread)
    {
        this->cartesianRateThread = cartesianRateThread;
    }

protected:
    /** Implement the actual responder (callback on RPC). */
    virtual bool read(yarp::os::ConnectionReader& connection);

    CartesianRateThread *cartesianRateThread;
};

}  // namespace teo

#endif

