//
// Created by mkajdak on 28.08.18.
//

#include <Factories/DetectorsFactory.hpp>
#include <Detectors/CollisionDetector.hpp>
#include <Detectors/EventDetector.hpp>



DetectorsFactory::DetectorsFactory()
    : _log("DetectorsFactory")
    , _collisionDetectorPtr (new CollisionDetector)
    , _eventDetectorPtr (new EventDetector)
{

}