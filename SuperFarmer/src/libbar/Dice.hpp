#pragma once

#include "Animal.hpp"
#include <vector>
#include <utility>

struct Dice{
    Dice();
    std::vector<Animal> _greenDice;
    std::vector<Animal> _redDice;
    std::pair<const Animal, const Animal> rollDice();
};

