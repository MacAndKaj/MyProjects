//
// Created by maciej on 27.08.18.
//

#ifndef PARANOID_EVENTDETECTOR_HPP
#define PARANOID_EVENTDETECTOR_HPP
#include <Interface/IDetector.hpp>
#include <Logger.hpp>

//TODO implement


class EventDetector : public IDetector
{
public:
    virtual ~EventDetector();
    void startMonitoring() override;
    void stopMonitoring() override;
private:
    EventDetector();
    Logger _log;
    friend class DetectorsFactory;
};

#endif //PARANOID_EVENTDETECTOR_HPP
