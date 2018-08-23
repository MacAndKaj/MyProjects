//
// Created by mkajdak on 17.08.18.
//
#include <gtest/gtest.h>
#include <cmath>
#include <Buttons/LetterButton.hpp>



class LetterButtonTests : public ::testing::Test
{

protected:


public:
    LetterButtonTests ()
    {
        this->_sut = std::make_unique<LetterButton>();
    }


    std::unique_ptr<LetterButton> _sut;

};


TEST_F(LetterButtonTests, LetterButtonTests_ShouldChangeState_Test)
{
    _sut->focus();
    _sut->click();
    ASSERT_TRUE(_sut->isClicked());
    _sut->unclick();
    ASSERT_FALSE(_sut->isClicked());
}

TEST_F(LetterButtonTests, LetterButtonTests_ShouldHandleFunctionality_Test)
{

    _sut->setFunctionality([](){});
    _sut->focus();
    _sut->click();
    _sut->unclick();
}
