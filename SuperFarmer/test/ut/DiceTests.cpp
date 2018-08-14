#include "gtest/gtest.h"
#include "Dice.hpp"
#include <iostream>

struct DiceTests : public ::testing::Test{
    DiceTests()
    {}
};

TEST_F(DiceTests, notEmpty) {
    Dice dice;
    EXPECT_FALSE(dice._greenDice.empty());
    EXPECT_FALSE(dice._redDice.empty());
}

TEST_F(DiceTests, checkSize) {
    Dice dice;
    EXPECT_EQ(dice._greenDice.size(), 12);
    EXPECT_EQ(dice._redDice.size(), 12);
}


