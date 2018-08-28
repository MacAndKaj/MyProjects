//
// Created by mkajdak on 28.08.18.
//

#ifndef PARANOID_ENGINE_HPP
#define PARANOID_ENGINE_HPP

#include <Factories/DetectorsModule.hpp>

namespace eng
{

class Engine
{
public:
    virtual ~Engine();
    const det::DetectorsModule &getDetectorsFactory() const;
protected:
    Engine();

private:
    std::unique_ptr<det::DetectorsModule> _detectorsModule;
    Logger _log;

};

} //eng

#endif //PARANOID_ENGINE_HPP
