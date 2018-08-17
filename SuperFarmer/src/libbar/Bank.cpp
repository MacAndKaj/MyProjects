#include "Bank.hpp"
#include <numeric>

Bank::Bank()
{
    _animalsAmount[Animal::rabbit] = 60;
    _animalsAmount[Animal::sheep] = 24;
    _animalsAmount[Animal::pig] = 20;
    _animalsAmount[Animal::cow] = 12;
    _animalsAmount[Animal::horse] = 6;
    _animalsAmount[Animal::smallDog] = 4;
    _animalsAmount[Animal::bigDog] = 2;  

    _animalsCost[Animal::rabbit] = 1;
    _animalsCost[Animal::sheep] = 6;
    _animalsCost[Animal::pig] = 12;
    _animalsCost[Animal::cow] = 36;
    _animalsCost[Animal::horse] = 72;
    _animalsCost[Animal::smallDog] = 6;
    _animalsCost[Animal::bigDog] = 36;  
}

Request Bank::getStatus() const
{

    return {};
}

void Bank::transferToPlayer(Player& player,
        Animal animal, int howManyAnimals)
{
    if(isTransferPossible(animal, howManyAnimals))
    {
        player.addAnimal(animal, howManyAnimals);
        _animalsAmount[animal] -= howManyAnimals;
    }
}

void Bank::transferFromPlayer(Player& player,
        Animal animal, int howManyAnimals)
{
    player.removeAnimal(animal, howManyAnimals);
    _animalsAmount[animal] += howManyAnimals;

}

bool Bank::isTransferPossible(Animal animal, int howManyAnimals)
{
    return _animalsAmount[animal] >= howManyAnimals;
}

int Bank::getRabbitEquivalent(Request& toCalculate)
{
    return std::accumulate(toCalculate.begin(), toCalculate.end(), 0,
        [&animalsCost](const auto& item)
        {
            return item.second * _animalsCost[item.first];
        });
}





