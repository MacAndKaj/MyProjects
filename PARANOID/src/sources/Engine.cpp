//
// Created by mkajdak on 28.08.18.
//

#include <Engine.hpp>

namespace eng
{

Engine::Engine()
        : _log("Engine")
        , _detectorsModule(new det::DetectorsModule())
{

}

Engine::~Engine()
{

}

const det::DetectorsModule &Engine::getDetectorsFactory() const
{
    return *_detectorsModule;
}

}