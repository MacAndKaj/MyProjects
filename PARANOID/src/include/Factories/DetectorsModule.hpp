//
// Created by mkajdak on 28.08.18.
//

#ifndef PARANOID_DETECTORSMODULE_HPP
#define PARANOID_DETECTORSMODULE_HPP

#include <Logger.hpp>

namespace eng
{
class Engine;

namespace det
{

class CollisionDetector;
class EventDetector;

class DetectorsModule
{
public:
    CollisionDetector &getCollisionDetector() const;
    EventDetector &getEventDetector() const;
    virtual ~DetectorsModule();
protected:
    DetectorsModule();

private:

    Logger _log;

    std::unique_ptr<CollisionDetector> _collisionDetectorPtr;
    std::unique_ptr<EventDetector> _eventDetectorPtr;
    friend class eng::Engine;
};
} //det
} //eng
#endif //PARANOID_DETECTORSMODULE_HPP
