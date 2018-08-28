//
// Created by maciej on 27.08.18.
//

#ifndef PARANOID_EVENTDETECTOR_HPP
#define PARANOID_EVENTDETECTOR_HPP

#include <Interface/IDetector.hpp>
#include <Logger.hpp>

namespace eng
{
class DetectorsModule;

namespace det
{

class EventDetector : public IDetector
{
public:
    virtual ~EventDetector();
    void startMonitoring() override;
    void stopMonitoring() override;
private:
    EventDetector();
    Logger _log;
    friend class DetectorsModule;
};

} // det
} // eng
#endif //PARANOID_EVENTDETECTOR_HPP
