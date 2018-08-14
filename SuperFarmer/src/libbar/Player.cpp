#include "Player.hpp"
#include <algorithm>

Player::Player() 
{
    _herd[Animal::rabbit] = 0;
    _herd[Animal::sheep] = 0;
    _herd[Animal::pig] = 0;
    _herd[Animal::cow] = 0;
    _herd[Animal::horse] = 0;
    
    _dogs[Animal::smallDog] = 0;
    _dogs[Animal::bigDog] = 0;  
}

bool Player::checkWin() const
{
    return std::all_of(_herd.begin(), _herd.end(), [](auto pair)
    {
        return pair.second > 0;
    });
}
void Player::addAnimal(Animal animal, int count)
{
    _herd[animal] += count;
}

void Player::removeAnimal(Animal animal, int count)
{
    _herd[animal] -= count; 
}




