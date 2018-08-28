//
// Created by maciej on 27.08.18.
//

#ifndef PARANOID_IDETECTOR_HPP
#define PARANOID_IDETECTOR_HPP

namespace eng
{

namespace det
{

class IDetector
{
public:
    virtual void startMonitoring() = 0;
    virtual void stopMonitoring() = 0;
};

} //det
} //det
#endif //PARANOID_IDETECTOR_HPP
