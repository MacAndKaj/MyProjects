//
// Created by mkajdak on 28.08.18.
//

#include <Factories/DetectorsModule.hpp>
#include <Detectors/CollisionDetector.hpp>
#include <Detectors/EventDetector.hpp>

namespace eng
{

namespace det
{

DetectorsModule::DetectorsModule()
        : _log("DetectorsModule")
        , _collisionDetectorPtr(new CollisionDetector)
        , _eventDetectorPtr(new EventDetector)
{

}


DetectorsModule::~DetectorsModule()
{

}

CollisionDetector &DetectorsModule::getCollisionDetector() const
{
    return *_collisionDetectorPtr;
}

EventDetector &DetectorsModule::getEventDetector() const
{
    return *_eventDetectorPtr;
}

} // det
} // eng