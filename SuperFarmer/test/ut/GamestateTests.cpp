#include "gtest/gtest.h"
#include "Gamestate.hpp"
#include <iostream>

struct GamestateTests : public ::testing::Test
{
    GamestateTests():_noPlayers(2) ,_sut(_noPlayers)
    {    
    }
    
    int _noPlayers;
    Gamestate _sut;
};

TEST_F(GamestateTests, )
{

}
