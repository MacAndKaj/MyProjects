//
// Created by maciej on 26.08.18.
//

#ifndef PARANOID_COLLISIONDETECTOR_HPP
#define PARANOID_COLLISIONDETECTOR_HPP

#include <Interface/IDetector.hpp>
#include <Logger.hpp>
//TODO implement

class DetectorsFactory;

class CollisionDetector : public IDetector
{
public:
    virtual ~CollisionDetector();
    void startMonitoring() override;
    void stopMonitoring() override;
private:
    CollisionDetector();
    Logger _log;
    friend class DetectorsFactory;
};

#endif //PARANOID_COLLISIONDETECTOR_HPP
