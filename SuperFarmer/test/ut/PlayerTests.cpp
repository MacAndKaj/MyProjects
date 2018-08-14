#include "gtest/gtest.h"
#include "Player.hpp"
#include <iostream>
#include "Bank.hpp"

struct PlayerTest : public ::testing::Test{
    PlayerTest()
    {}
};

TEST_F(PlayerTest, EmptyPlayerCannotWin)
{
    Player player;
    ASSERT_FALSE(player.checkWin());
}

TEST_F(PlayerTest, FullPlayerShouldWin)
{
    Player player;
    player._herd[Animal::rabbit] = 1;
    player._herd[Animal::sheep] = 1;
    player._herd[Animal::pig] = 1;
    player._herd[Animal::cow] = 1;
    player._herd[Animal::horse] = 1;

    ASSERT_TRUE(player.checkWin());
}

TEST_F(PlayerTest, HalfPlayerShouldNotWin)
{
    Player player;
    player._herd[Animal::sheep] = 1;
    player._herd[Animal::cow] = 1;
    player._herd[Animal::horse] = 1;

    ASSERT_FALSE(player.checkWin());
}

TEST_F(PlayerTest, ShouldIncrementAnimalsAfterTransfer)
{
    Player player;
    auto animal = Animal::rabbit;
    auto initialRabbitNumber = player._herd[animal];
    player.addAnimal(animal,1);
    ASSERT_EQ(player._herd[animal], initialRabbitNumber+1);
}

TEST_F(PlayerTest, ShouldDecrementAnimalsAfterTransfer)
{
    Player player;
    auto animal = Animal::rabbit;
    auto initialAnimalsCount = 10;
    auto animalsToRemove = 5;
    player._herd[animal] = initialAnimalsCount;

    player.removeAnimal(animal,animalsToRemove);
    ASSERT_EQ(player._herd[animal], initialAnimalsCount - animalsToRemove);
}



