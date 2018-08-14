#pragma once

#include <map>
#include "Animal.hpp"

struct Player
{
    Player();

    std::map<Animal, int> _herd;
    std::map<Animal, int> _dogs;
    bool checkWin() const;
    void addAnimal(Animal animal, int count);
    void removeAnimal(Animal animal, int count);
};