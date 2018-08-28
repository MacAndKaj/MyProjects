//
// Created by maciej on 27.08.18.
//

#ifndef PARANOID_IDETECTOR_HPP
#define PARANOID_IDETECTOR_HPP

class IDetector
{
public:
    virtual void startMonitoring() = 0;
    virtual void stopMonitoring() = 0;
};

#endif //PARANOID_IDETECTOR_HPP
