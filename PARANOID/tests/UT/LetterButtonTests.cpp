//
// Created by mkajdak on 17.08.18.
//
#include <gtest/gtest.h>
#include <cmath>
#include <mocks/MockSfColor.cpp>
#include <Buttons/LetterButton.hpp>
#include <mocks/MockSfFont.cpp>


class LetterButtonTests : public ::testing::Test
{

protected:

    virtual void SetUp ()
    {
        this->_sut.reset(new LetterButton());
    }

public:
    LetterButtonTests ()
    {
        this->_sut = std::make_unique<LetterButton>(LetterButton());
    }


    std::unique_ptr<LetterButton> _sut;

};

TEST_F(LetterButtonTests, ShouldDoSomething) // NOLINT
{
    _sut->click();
    ASSERT_TRUE(_sut->isClicked());
    _sut->unclick();
    ASSERT_FALSE(_sut->isClicked());
}

