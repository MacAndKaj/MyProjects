#include "gtest/gtest.h"
#include "Bank.hpp"
#include <iostream>

TEST(BankTests, shouldNotBeEmptyAfterInitialization)
{
    Bank mbank;
    ASSERT_FALSE(mbank._animalsCost.empty());
    ASSERT_FALSE(mbank._animalsAmount.empty());
}



TEST(BankTests, shouldDecreaseAnimalNumber)
{
    Bank mbank;
    Player player;
    auto animal = Animal::rabbit;
    auto howManyRabbits = 1;
    auto amountOfRabbits = mbank._animalsAmount[animal];
    mbank.transferToPlayer(player, animal, howManyRabbits);
    ASSERT_EQ(mbank._animalsAmount[animal],
                amountOfRabbits - howManyRabbits);    
}

TEST(BankTests, canIGetAnimal)
{
    Bank mbank;
    auto animal = Animal::rabbit;
    auto amountOfRabbits = mbank._animalsAmount[animal];

    ASSERT_TRUE(mbank.isTransferPossible(animal, amountOfRabbits));
}


TEST(BankTests, shouldNotBeNegativeNumberOfAnimals)
{
    Bank mbank;
    Player player;
    auto animal = Animal::rabbit;
    auto amountOfRabbits = mbank._animalsAmount[animal];
    mbank.transferToPlayer(player, animal, amountOfRabbits);
    ASSERT_FALSE(mbank.isTransferPossible(animal, 1));
}


TEST(BankTests, shouldIncreaseAnimalNumber)
{
    Bank mbank;
    Player player;
    auto animal = Animal::rabbit;
    auto howManyRabbits = 1;
    auto amountOfRabbits = mbank._animalsAmount[animal];
    player._herd[animal] = howManyRabbits;

    mbank.transferFromPlayer(player, animal, howManyRabbits);

    ASSERT_EQ(mbank._animalsAmount[animal],
                amountOfRabbits + howManyRabbits);    
}



