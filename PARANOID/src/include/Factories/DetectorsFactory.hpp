//
// Created by mkajdak on 28.08.18.
//

#ifndef PARANOID_DETECTORSFACTORY_HPP
#define PARANOID_DETECTORSFACTORY_HPP

#include <Logger.hpp>

//TODO implement
class EngineModule;
class CollisionDetector;
class EventDetector;

class DetectorsFactory
{
protected:
    DetectorsFactory();

private:
    friend class BasicModule;

    Logger _log;

    std::unique_ptr<CollisionDetector> _collisionDetectorPtr;
    std::unique_ptr<EventDetector> _eventDetectorPtr;
};


#endif //PARANOID_DETECTORSFACTORY_HPP
