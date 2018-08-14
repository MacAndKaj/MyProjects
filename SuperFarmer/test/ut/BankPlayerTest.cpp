#include "gtest/gtest.h"
#include "Bank.hpp"
#include <iostream>


TEST(BankTests, shouldTransferAnimalsToPlayer)
{
    Bank mbank;
    Player player;
    auto animal = Animal::rabbit;
    auto howManyRabbits = 5;
    auto amountOfRabbits = mbank._animalsAmount[animal];

    mbank.transferToPlayer(player, animal, howManyRabbits);

    ASSERT_EQ(player._herd[animal], howManyRabbits);    
}

TEST(BankTests, shouldTransferAnimalsToBank)
{
    Bank mbank;
    Player player;
    auto animal = Animal::rabbit;
    auto howManyRabbits = 5;
    player._herd[animal] = howManyRabbits;

    mbank.transferFromPlayer(player, animal, howManyRabbits);

    ASSERT_EQ(player._herd[animal], 0);    
}






