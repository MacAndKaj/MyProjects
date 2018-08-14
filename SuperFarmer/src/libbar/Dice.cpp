#include "Dice.hpp"
#include <cstdlib>

Dice::Dice(){
    _greenDice = 
    {
        Animal::wolf,
        Animal::cow,
        Animal::pig,
        Animal::sheep,
        Animal::sheep,
        Animal::sheep,
        Animal::rabbit,
        Animal::rabbit,
        Animal::rabbit,
        Animal::rabbit,
        Animal::rabbit,
        Animal::rabbit
    };

    _redDice = 
    {
        Animal::fox,
        Animal::horse,
        Animal::pig,
        Animal::pig,
        Animal::sheep,
        Animal::sheep,
        Animal::rabbit,
        Animal::rabbit,
        Animal::rabbit,
        Animal::rabbit,
        Animal::rabbit,
        Animal::rabbit
    };

        srand(745);
};

std::pair<const Animal, const Animal> Dice::rollDice()
{
    return std::make_pair(
        _redDice[rand()%_redDice.size()], 
        _greenDice[rand()%_greenDice.size()]
        );
}