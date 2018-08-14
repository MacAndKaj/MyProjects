#include <map>
#include <vector>
#include <utility>
#include "Animal.hpp"
#include "Player.hpp"

using Request = std::map<Animal, int>;

struct Bank 
{
    Request _animalsCost;
    Request _animalsAmount;

    Bank();

    Request getStatus() const;
    
    void transferToPlayer(Player& player,
        Animal animal, int howManyAnimals);
    
    void transferFromPlayer(Player& player,
        Animal animal, int howManyAnimals);
    
    bool isTransferPossible(Animal animal, int howManyAnimals);
    int getRabbitEquivalent(Request& toGet);
};